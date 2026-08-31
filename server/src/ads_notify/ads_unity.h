#ifndef __ADS_UNITY_NOTIFY_H__
#define __ADS_UNITY_NOTIFY_H__

#include <string>
#include <map>
#include <algorithm>

class AdsUnityNotify
{
private:
    class Request
    {
    public:
        Request()
        {

        }
        Request(const std::string &json)
        {
            this->Deserialize(json);
        }
        template <typename Writer>
        void Serialize(Writer &writer) const
        {
            writer.StartObject();
            SERIALIZE_MEMBER(writer, p1);
            SERIALIZE_MEMBER(writer, p2);
            SERIALIZE_MEMBER(writer, p3);
            SERIALIZE_MEMBER(writer, p4);
            SERIALIZE_MEMBER(writer, p5);
            SERIALIZE_MEMBER(writer, p6);
            SERIALIZE_MEMBER(writer, p7);
            SERIALIZE_MEMBER(writer, p8);
            SERIALIZE_MEMBER(writer, p9);
            SERIALIZE_MEMBER(writer, commonCards);
            writer.EndObject();
        }

        void toString(std::string &json)
        {
            StringBuffer sb;
            Writer<StringBuffer> writer(sb);
            Serialize(writer);
            json = sb.GetString();
        }

        void Deserialize(const string &json)
        {
            try
            {
                Document d;
                if (d.Parse(json.c_str()).HasParseError())
                {
                    throw logic_error("");
                }
                SET_DOC_MEMBER(d, p1);
                SET_DOC_MEMBER(d, p2);
                SET_DOC_MEMBER(d, p3);
                SET_DOC_MEMBER(d, p4);
                SET_DOC_MEMBER(d, p5);
                SET_DOC_MEMBER(d, p6);
                SET_DOC_MEMBER(d, p7);
                SET_DOC_MEMBER(d, p8);
                SET_DOC_MEMBER(d, p9);
                SET_DOC_MEMBER(d, commonCards);
            }
            catch (const std::exception &e)
            {
                std::string errInfo = ::toString(__FILE__, ":", __LINE__, ":解码失败!");
                throw logic_error(errInfo);
            }
        }

        // 从16进制解析出牌
        std::vector<int16_t> parseCards(const CString &raw_cards)
        {
            std::vector<int16_t> cards;
            std::string cardsStr = raw_cards;
            std::vector<std::string> cardStrVec = split(cardsStr, "|");
            for (const auto &elem : cardStrVec)
            {
                int32_t value = std::stoi(elem, 0, 16);
                cards.push_back(value);
            }
            return cards;
        }

        std::string getCardDesc(int16_t card)
        {
            int8_t value = card % 16;
            int8_t color = card / 16;
            std::string colorDesc;
            std::string valueDesc;

            const static std::map<int8_t, std::string> mColorDesc =
            {
                {0x00, "方块"}, { 0x01, "梅花" }, { 0x02, "红桃" }, { 0x03, "黑桃" }
            };
            auto itColor = mColorDesc.find(color);
            colorDesc = itColor == mColorDesc.end() ? "其它花色" : itColor->second;

            const static std::map<int8_t, std::string> mValueDesc =
            {
                { 0x0E, "A" }, { 0x0D, "K" }, { 0x0C, "Q" }, { 0x0B, "J" }
            };
            auto itValue = mValueDesc.find(value);
            valueDesc = itValue == mValueDesc.end() ? std::to_string(value) : itValue->second;
            std::string cardDesc = colorDesc + valueDesc;
            return cardDesc;
        }
        void padCards(std::map<std::string, std::vector<int16_t>> &mCards)
        {
            const static int16_t commonCardCount    = 5;
            const static int16_t handCardCount      = 2;
            std::vector<int16_t> allCards =
            {
                0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
                0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E,
                0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E,
                0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E
            };


            std::vector<int16_t> allAdsUnityNotifys;
            for (auto &item : mCards)
            {
                std::copy(item.second.begin(), item.second.end(), std::back_inserter(allAdsUnityNotifys));
            }

            std::random_shuffle(allCards.begin(), allCards.end());
            for (auto &card : allAdsUnityNotifys)
            {
                auto it = std::find(allCards.begin(), allCards.end(), card);
                if (it == allCards.end())
                {
                    throw logic_error("配牌重复!重复的牌是:" + getCardDesc(card));
                }
                allCards.erase(it);
            }

            int32_t curIndx = 0;
            for (auto &elem : mCards)
            {
                const std::string &key = elem.first;
                std::vector<int16_t> &vec = elem.second;
                size_t len = vec.size();
                int16_t delta = key == "commonCards" ? (commonCardCount - len) : (handCardCount - len);
                if (delta > 0)
                {
                    std::copy(allCards.begin() + curIndx, allCards.begin() + curIndx + delta, std::back_inserter(vec));
                    curIndx += delta;
                }
            }
        }

        void parseCards()
        {
            std::map<std::string, std::vector<int16_t>> mCards;
            mCards["p1"] = parseCards(_p1);
            mCards["p2"] = parseCards(_p2);
            mCards["p3"] = parseCards(_p3);
            mCards["p4"] = parseCards(_p4);
            mCards["p5"] = parseCards(_p5);
            mCards["p6"] = parseCards(_p6);
            mCards["p7"] = parseCards(_p7);
            mCards["p8"] = parseCards(_p8);
            mCards["p9"] = parseCards(_p9);
            mCards["commonCards"] = parseCards(_commonCards);


            padCards(mCards);
            auto &configure_cards = AdsUnityNotify::getArrangeCards();
            configure_cards.vecHd.clear();
            for (auto &elem : mCards)
            {
                const std::string &key = elem.first;
                const std::vector<int16_t> value = elem.second;
                if (key == "commonCards")
                {
                    configure_cards.vecComm = value;
                }
                else
                {
                    std::copy(value.begin(), value.end(), std::back_inserter(configure_cards.vecHd));
                }
            }
            std::reverse(configure_cards.vecHd.begin(), configure_cards.vecHd.end());
            std::reverse(configure_cards.vecComm.begin(), configure_cards.vecComm.end());
        }
    private:
        CString         _p1;  //玩家一的牌
        CString         _p2;
        CString         _p3;
        CString         _p4;
        CString         _p5;
        CString         _p6;
        CString         _p7;
        CString         _p8;
        CString         _p9;
        CString         _commonCards; //公共牌
    };

    class Response
    {
    public:
        Response(const string &json)
        {
            this->Deserialize(json);
        }
        template <typename Writer>
        void Serialize(Writer &writer) const
        {
            writer.StartObject();
            SERIALIZE_MEMBER(writer, status);
            writer.EndObject();
        }

        void toString(std::string &json)
        {
            StringBuffer sb;
            Writer<StringBuffer> writer(sb);
            Serialize(writer);
            json = sb.GetString();
        }

        void Deserialize(const string &json)
        {
            Document d;
            if (d.Parse(json.c_str()).HasParseError())
            {
                throw logic_error("parse json error. raw data : " + json);
            }
            SET_DOC_MEMBER(d, status);
        }
    private:
        CString  _status;  //状态
    };

public:
    static tars::Int32 getCards(gm::GetCardsResp &resp)
    {
        auto &configure_cards = AdsUnityNotify::getArrangeCards();
        if (configure_cards.vecHd.empty() != true)
        {
            resp = configure_cards;
        }
        return 0;
    }

    static tars::Int32 handler(const vector<tars::Char> &reqBuf, const map<std::string, std::string> &extraInfo, vector<tars::Char> &rspBuf)
    {
        Request request;
        decode(reqBuf, request);
        request.parseCards();

        GMResponse rsp(1, "", "succ", 100, 9);
        std::string resultJson;
        rsp.toString(resultJson);
        rspBuf.assign(resultJson.begin(), resultJson.end());
        return 0;
    }

private:
    static gm::GetCardsResp &getArrangeCards()
    {
        static gm::GetCardsResp configure_cards;
        return configure_cards;
    }
};

#endif