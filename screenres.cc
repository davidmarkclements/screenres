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

void set(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  int code = changeRes(info[0]->Uint32Value(), info[1]->Uint32Value());

  if (!code) {
  return;
  } else {
    //NanReturnValue(Nan::New<Number>(code));
    info.GetReturnValue().Set(code);
  }
}

void get(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  Resolution res = fetchRes();
  Local<Array> arr = Nan::New<Array>(2);
  arr->Set(0, Nan::New<Number>(res.width));
  arr->Set(1, Nan::New<Number>(res.height));
  info.GetReturnValue().Set(arr);
  //NanReturnValue(arr);
}

void init(Handle<Object> exports) {
  exports->Set(Nan::New("set").ToLocalChecked(), Nan::New<FunctionTemplate>(set)->GetFunction());
  exports->Set(Nan::New("get").ToLocalChecked(), Nan::New<FunctionTemplate>(get)->GetFunction());
}

NODE_MODULE(screenres, init);
