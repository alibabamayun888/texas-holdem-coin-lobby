#ifndef __CERTAIN_VICTORY_CONFIG_DETAIL_H__
#define __CERTAIN_VICTORY_CONFIG_DETAIL_H__
class CertainVictoryConfigDetailRequest
{
public:
	CertainVictoryConfigDetailRequest(const string& json) {
		this->Deserialize(json);
	}
	template <typename Writer>
	void Serialize(Writer& writer) const {
		writer.StartObject();
		SERIALIZE_MEMBER(writer,id);

		writer.EndObject();
	}

	void toString(std::string& json) {
		StringBuffer sb;
		Writer<StringBuffer> writer(sb);
		Serialize(writer);
		json = sb.GetString();
	}

	void Deserialize(const string& json)
	{
		Document d;
		if (d.Parse(json.c_str()).HasParseError()){
			throw logic_error("parse json error. raw data : " + json);
		}
		SET_DOC_MEMBER(d,id);

	}

	static tars::Int32 handler(const vector<tars::Char>& reqBuf, const map<std::string, std::string>& extraInfo, vector<tars::Char>& rspBuf)
	{
	    return 0;
	}
private:
	CInteger       	_id             ;  //主键

};
class CertainVictoryConfigDetailResponse
{
public:
	CertainVictoryConfigDetailResponse(const string& json) {
		this->Deserialize(json);
	}
	template <typename Writer>
	void Serialize(Writer& writer) const {
		writer.StartObject();
		SERIALIZE_MEMBER(writer,id);
		SERIALIZE_MEMBER(writer,uids);
		SERIALIZE_MEMBER(writer,rate);
		SERIALIZE_MEMBER(writer,roomIds);
		SERIALIZE_MEMBER(writer,times);
		SERIALIZE_MEMBER(writer,optUser);
		SERIALIZE_MEMBER(writer,createDate);

		writer.EndObject();
	}

	void toString(std::string& json) {
		StringBuffer sb;
		Writer<StringBuffer> writer(sb);
		Serialize(writer);
		json = sb.GetString();
	}

	void Deserialize(const string& json)
	{
		Document d;
		if (d.Parse(json.c_str()).HasParseError()){
			throw logic_error("parse json error. raw data : " + json);
		}
		SET_DOC_MEMBER(d,id);
		SET_DOC_MEMBER(d,uids);
		SET_DOC_MEMBER(d,rate);
		SET_DOC_MEMBER(d,roomIds);
		SET_DOC_MEMBER(d,times);
		SET_DOC_MEMBER(d,optUser);
		SET_DOC_MEMBER(d,createDate);

	}

	static tars::Int32 handler(const vector<tars::Char>& reqBuf, const map<std::string, std::string>& extraInfo, vector<tars::Char>& rspBuf)
	{
	    return 0;
	}
private:
	CInteger       	_id             ;  //主键
	CInteger       	_uids           ;  //玩家id
	CInteger       	_rate           ;  //触发几率例子：10%
	CString        	_roomIds        ;  //有效房间
	CInteger       	_times          ;  //触发次数(必胜牌累计触发次数，玩家每次触发后次数-1，当次数为0时移除名单)
	CString        	_optUser        ;  //操作者
	CString        	_createDate     ;  //创建时间

};
#endif