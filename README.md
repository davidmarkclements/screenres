# screenres

Cross platform screen resolution module and CLI tool

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

* Windows
* Linux 
* macOS

## License

MIT

## Acknowledgements

Sponsored by [nearForm](http://nearform.com)




