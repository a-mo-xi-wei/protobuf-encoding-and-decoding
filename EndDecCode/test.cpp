#include <iostream>
#include "Request.h"
#include "Response.h"

using namespace std;

//编码
string encodeMsg(Codec* codec) {
	return codec->encodeMsg();
}
//解码
void* decodeMsg(Codec* codec) {
	return codec->decodeMsg();
}
int main() {
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.clientID = "OnePiece";
	reqInfo.serverID = "Luffy";
	reqInfo.data = "饿货来条士力架";
	reqInfo.sign = "朝你扔大粪";
	RequestCodec req(&reqInfo);\
	//编码
	string reqmsg = encodeMsg(&req);
	//解码
	RequestCodec reql(reqmsg);
	RequestMsg* reqMsg = (RequestMsg*)decodeMsg(&reql);
	cout << "cmdType : " << reqMsg->cmdtype()
		<< ", clientID : " << reqMsg->clientid()
		<< ", serverID : " << reqMsg->serverid()
		<< ", data : " << reqMsg->data()
		<< ", sign : " << reqMsg->sign() << endl;
	//////////////////////////////////////////////////
	//////////////////////////////////////////////////
	RespondInfo resInfo;
	resInfo.status = false;
	resInfo.clientID = "威桑";
	resInfo.serverID = "py桑";
	resInfo.data = "go桑";
	resInfo.seckeyID = 345;
	RespondCodec res(&resInfo);
	//编码
	string resmsg = encodeMsg(&res);
	//解码
	RespondCodec resl(resmsg);
	RespondMsg* resMsg = (RespondMsg*)decodeMsg(&resl);
	cout << "status : " << resMsg->status()
		<< ", clientID : " << resMsg->clientid()
		<< ", serverID : " << resMsg->serverid()
		<< ", data : " << resMsg->data()
		<< ", seckeyID : " << resMsg->seckeyid() << endl;

}