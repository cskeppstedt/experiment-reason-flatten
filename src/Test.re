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
  print_endline "]";
};

let flatten_input = ListOfLists [List [1, 2], List [3], ListOfLists [List [4], List [5]]];

print_list (flatten flatten_input);
