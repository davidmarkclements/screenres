var screenres = require('bindings')('screenres');

var errs = {
  49: 'ERR_MISSING_H_OR_V',
  50: 'ERR_UNABLE_TO_CHANGE_RESOLUTION'
};

exports.set = function () {
  var code = screenres.set.apply(screenres, arguments);
  if (!code) {return;}
  return Error(errs[code]);
}

exports.get = screenres.get;