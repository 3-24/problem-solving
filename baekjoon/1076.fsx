open System

let amap = dict["black", 0 ;
    "brown", 1;
    "red", 2;
    "orange", 3;
    "yellow", 4;
    "green", 5;
    "blue", 6;
    "violet", 7;
    "grey", 8;
    "white", 9
    ]

let str1 = Console.ReadLine()
let str2 = Console.ReadLine()
let str3 = Console.ReadLine()
let n1 = amap.Item(str1)
let n2 = amap.Item(str2)
let n3 = amap.Item(str3)
let m = 10*n1 + n2
m |> printf "%d"
let rec printchars c n =
  match n with
  | 0 -> ()
  | _ ->
    printf "%c" c
    printchars c (n-1)
if (m <> 0) then printchars '0' n3 else ()