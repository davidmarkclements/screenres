
# screenres

Get and set screen resolutions

## Usage

### Programmatic

```sh
$ npm install screenres --save
```

#### get

```js
var sr = require('screenres');
console.log(sr.get()); // [1440, 900]
```

#### set

```js
var sr = require('screenres');
sr.set(800, 600));
```

### CLI

```sh
$ npm install -g screenres
```

#### help

```sh
$ screenres --help
```

#### get

```sh
$ screenres
1440x900
```


#### set

```sh
$ screenres 800 600
```

## Platforms

Currently only supports OS X, easy to add new platforms, see contributing

## Contributing

It would be nice to have a multi-platform screen resolution tool.

It would also be super easy to make happen.

If you'd like to add a new platform, write a c++ file named after the platform,
(e.g. linux.cc). The file should include `headers.h` and implement two functions:

```c++
Resolution fetchRes();
int changeRes(int h, int v);
```

`Resolution` is simply a struct with `height` and `width` `int`s.

The new platform file should also check for platform, e.g.:

```c++
#ifdef _linux
 //linux screenres implementation
#endif
```

Finally, add the new file to `bindings.gyp` in the `sources` array,
and define any conditional configuration (e.g. like linked libraries).

That should be it `npm run configure; npm run build`. 

Then.. send a PR :)

## Kudos

Sponsored by [nearForm](http://nearform.com)




