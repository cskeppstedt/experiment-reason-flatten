# experiment-flatten-reason

This project is cloned from
[ReasonProject](https://github.com/facebook/reason/blob/master/README.md#install-via-npm)
which was the recommended way of installation at this time. Everything comes
from that repo except [the implementation](src/Test.re).

- Flattens an arbitrarily nested list of numbers.
- Regular List cannot be nested, since lists must contain one type only. So a
  list of type `a` cannot contain an item that is `list a`. I added a custom
  data constructor type `lists` to deal with this.
- I couldn't find anything that prints Lists, so I also had to add that.
- Made two variants on the implementation, the second one is a bit cleaner than
  the first one. The first one was removed in [a recent
  commit](https://github.com/cskeppstedt/experiment-reason-flatten/commit/275a34e547c86ad420e9ec6e10e9c90333022f8e).

## Usage

```
npm install # may take a while, ocaml compilation seems to be happening here
npm start
```

`npm start` is an alias that performs `npm run reasonBuild` (compiles the
binary) and `npm run exec` (executes the binary).

```
npm run editor # starts the editor with utilities appended to $PATH
```

