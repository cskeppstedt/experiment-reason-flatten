/* ====================================
 *  Type definition and implementation
 * ==================================== */
type nested_list =
  | Item int
  | Nested (list nested_list);

let rec flatten input =>
  switch input {
  | [] => []
  | [head, ...rest] =>
    switch head {
    | Item n => [n, ...flatten rest]
    | Nested ns => flatten ns @ flatten rest
    }
  };

/* ====================================
 *  Utility functions to print lists
 * ==================================== */
let rec print_content content =>
  switch content {
  | [] => ()
  | [head, ...rest] =>
    print_int head;
    print_string " ";
    print_content rest
  };

let rec print_list lst => {
  print_string "[ ";
  print_content lst;
  print_endline "]"
};

/* ====================================
 *  Create input and run example
 * ==================================== */
let flatten_input = [Item 1, Item 2, Nested [Item 3, Item 4], Nested [Nested [Item 5]]];

print_list (flatten flatten_input); /* outputs [ 1 2 3 4 5 ] */
