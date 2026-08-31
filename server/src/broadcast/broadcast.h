#ifndef __BROADCAST_H__
#define __BROADCAST_H__
#include <stdexcept>
#include "../Define.h"
#include "../LogComm.h"
#include "utilityFunction.h"
#include "GMServer.h"

class BroadcastRequest
{
    friend class BroadcastResponse;
public:
    BroadcastRequest() {}
    BroadcastRequest(const std::string &json)
    {
        this->Deserialize(json);
    }
    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        SERIALIZE_MEMBER(writer, iTime);
        writer.EndObject();
    }

    void toString(std::string &json)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        Serialize(writer);
        json = sb.GetString();
    }

    void Deserialize(const std::string &json)
    {
        try
        {
            Document d;
            if (d.Parse(json.c_str()).HasParseError())
            {
                throw std::logic_error("parse json error. raw data : " + json);
            }
            SET_DOC_MEMBER(d, iTime);
        }
        catch (const std::exception &e)
        {
            std::string errInfo = ::toString(__FILE__, ":", __LINE__, ":ServerUpdateNotifyRequest decode error!");
            throw std::logic_error(errInfo);
        }
    }

private:
    CInteger _iTime;  //更新时间(分钟)
};

class BroadcastResponse
{
public:
    BroadcastResponse() {}
    BroadcastResponse(const string &json)
    {
        this->Deserialize(json);
    }
    
    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        SERIALIZE_MEMBER(writer, iTime);
        writer.EndObject();
    }

    void toString(std::string &json)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        Serialize(writer);
        json = sb.GetString();
    }

    void Deserialize(const std::string &json)
    {
        try
        {
            Document d;
            if (d.Parse(json.c_str()).HasParseError())
            {
                throw std::logic_error("parse json error. raw data : " + json);
            }
            SET_DOC_MEMBER(d, iTime);
        }
        catch (const std::exception &e)
        {
            std::string errInfo = ::toString(__FILE__, ":", __LINE__, ":ServerUpdateNotifyRequest decode error!");
            throw std::logic_error(errInfo);
        }
    }

    static tars::Int32 handler(const vector<tars::Char> &reqBuf, const map<std::string, std::string> &extraInfo, vector<tars::Char> &rspBuf)
    {
        // STEP1 解码
        BroadcastRequest request;
        decode(reqBuf, request);

        // STEP2 具体业务处理
        int64_t resultCode = RESULT_CODE_SUCCESS;
        int iRet = g_app.getOuterFactoryPtr()->getPushServerPrx(request._iTime)->serverUpdateNotifyAll(request._iTime);
        if (iRet != 0)
        {
            ROLLLOG_ERROR << "serverUpdateNotifyAll failed, iRet:" << iRet << ", request._iTime:" << request._iTime << endl;
            resultCode = RESULT_CODE_FAIL;
        }

        // STEP3 填充数据
        encode(resultCode, request, rspBuf);
        return 0;
    }

private:

    static void encode(int64_t resultCode, BroadcastRequest &request, vector<tars::Char> &rspBuf)
    {
        BroadcastResponse  response;
        response._iTime.assign(request._iTime);

        // resultData是数组
        std::string json;
        response.toString(json);
        std::string resultData = "[" + json + "]";

        int64_t totalItems = 1;  //总条数
        int64_t totalPages = 1;  //总页数
        GMResponse rsp(resultCode, "", resultData, totalItems, totalPages);
        std::string resultJson;
        rsp.toString(resultJson);
        rspBuf.assign(resultJson.begin(), resultJson.end());
    }

private:
    CInteger _iTime;  //更新时间(分钟)
};
#endif