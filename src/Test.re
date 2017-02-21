type lists =
  | List (list int)
  | ListOfLists (list lists);

let rec flatten input =>
  switch input {
  | List xs => xs
  | ListOfLists [head, ...rest] => List.fold_left (fun a b => a @ flatten b) (flatten head) rest
  | ListOfLists _ => []
  };

let rec print_list lst =>
  switch lst {
  | [] => ()
  | [e, ...l] =>
    print_int e;
    print_string " ";
    print_list l
  };

let flatten_input = ListOfLists [List [1, 2], List [3], ListOfLists [List [4], List [5]]];

print_list (flatten flatten_input);
