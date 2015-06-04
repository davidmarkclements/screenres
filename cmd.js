#!/usr/bin/env node

var sr = require('./');
var argv = require('minimist')(process.argv.slice(2));
var dims;

if (argv.help || argv.h) {
  return usage();
}

if (!argv._.length) {
  dims = sr.get();
  console.log('%dx%d', dims[0], dims[1]);
  return;
}

if (argv.length === 2) {

  return;
}

usage();

function usage() { 
  console.log()
  console.log(require('fs').readFileSync('./usage.txt')+'');
  console.log()
}