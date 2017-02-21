/** Type definition and implementation */
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


/** Utility functions to print lists, and nested lists.  */
let rec print_list lst => {
  print_string "[ ";
  print_string (String.concat " " (List.map string_of_int lst));
  print_endline " ]"
};

let print_nested input => {
  let rec print_elements elements =>
    switch elements {
    | [] => ()
    | [head, ...rest] =>
      switch head {
      | Item n =>
        print_int n;
        print_string " ";
        print_elements rest
      | Nested ns =>
        print_string "[ ";
        print_elements ns;
        print_string "] ";
        print_elements rest
      }
    };
  print_string "[ ";
  print_elements input;
  print_endline "]"
};


/** Run example */
let flatten_input = [Nested [Item 1, Item 2, Nested [Item 3]], Item 4];

print_string "Input:  ";

print_nested flatten_input; /* [ [ 1 2 [ 3 ] ] 4 ] */

print_string "Result: ";

print_list (flatten flatten_input); /* [ 1 2 3 4 ] */
