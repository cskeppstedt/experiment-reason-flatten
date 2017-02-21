# experiment-flatten-reason

This project is cloned from
[ReasonProject](https://github.com/facebook/reason/blob/master/README.md#install-via-npm)
which was the recommended way of installation at this time.

- Flattens an arbitrarily nested list of numbers
- Regular List cannot be nested, since lists must contain one type only. So a
  list of type `a` cannot contain an item that is `list a`. I added a custom
  data constructor type `lists` to deal with this.
- I couldn't find anything that prints Lists, so I also had to add that.

## Usage

```
npm install
npm start
```

`npm start` is an alias that performs `npm run reasonBuild` (compiles the
binary) and `npm run exec` (executes the binary).

