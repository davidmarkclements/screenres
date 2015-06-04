/*
*  screenres.cc
*  David Mark Clements 2015
*  @davidmarkclem
*
*/

#include <node.h>
#include <nan.h>
#include <string>

#include "headers.h"

using v8::Local;
using v8::Handle;
using v8::Object;
using v8::Array;
using v8::Number;
using v8::String;
using v8::FunctionTemplate;

void init(Handle<Object>);

NAN_METHOD(set) {
	NanScope();
	int code = changeRes(args[0]->Uint32Value(), args[1]->Uint32Value());

	if (!code) {
		NanReturnUndefined();
	} else {
	  NanReturnValue(NanNew<Number>(code));
	}
}

NAN_METHOD(get) {
	NanScope();
	Resolution res = fetchRes();
  Local<Array> arr = NanNew<Array>(2);
  arr->Set(0, NanNew<Number>(res.width));
  arr->Set(1, NanNew<Number>(res.height));
  NanReturnValue(arr);
}

void init(Handle<Object> exports) {
	exports->Set(NanNew<String>("set"), NanNew<FunctionTemplate>(set)->GetFunction());
	exports->Set(NanNew<String>("get"), NanNew<FunctionTemplate>(get)->GetFunction());
}

NODE_MODULE(screenres, init);
