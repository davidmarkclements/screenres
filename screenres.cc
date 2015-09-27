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
  Nan::HandleScope scope;
  int code = changeRes(info[0]->Uint32Value(), info[1]->Uint32Value());

  if (!code) {
    info.GetReturnValue().SetUndefined();
  } else {
    info.GetReturnValue().Set(Nan::New<Number>(code));
  }
}

NAN_METHOD(get) {
  Nan::HandleScope scope;
  Resolution res = fetchRes();
  Local<Array> arr = Nan::New<Array>(2);
  arr->Set(0, Nan::New<Number>(res.width));
  arr->Set(1, Nan::New<Number>(res.height));
  info.GetReturnValue().Set(arr);
}

NAN_MODULE_INIT (init) {
  Nan::Set(target, Nan::New<String>("set").ToLocalChecked(), Nan::New<FunctionTemplate>(set)->GetFunction());
  Nan::Set(target, Nan::New<String>("get").ToLocalChecked(), Nan::New<FunctionTemplate>(get)->GetFunction());
}

NODE_MODULE(screenres, init);
