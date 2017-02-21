/* =============================
 * Implementation variant #1
 * ============================= */
type lists =
  | List (list int)
  | ListOfLists (list lists);

let rec flatten input =>
  switch input {
  | List xs => xs
  | ListOfLists [head, ...rest] =>
    List.fold_left (fun accumulator element => accumulator @ flatten element) (flatten head) rest
  | ListOfLists _ => []
  };

/* =============================
 * Implementation variant #2
 * ============================= */
type lists2 =
  | Item int
  | Nested (list lists2);

let rec flatten2 input =>
  switch input {
  | [] => []
  | [head, ...rest] =>
    switch head {
    | Item n => [n, ...flatten2 rest]
    | Nested ns => flatten2 ns @ flatten2 rest
    }
  };

/* =============================
 * Utility functions
 * ============================= */
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

/* =============================
 * Run examples
 * ============================= */
let flatten_input = ListOfLists [List [1, 2], List [3], ListOfLists [List [4], List [5]]];

print_list (flatten flatten_input);

let flatten_input2 = [Item 1, Item 2, Nested [Item 3, Item 4], Nested [Nested [Item 5]]];

print_list (flatten2 flatten_input2);
