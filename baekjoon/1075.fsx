open System

let str1 =  Console.ReadLine()
let str2 = Console.ReadLine()
let n = ((Int32.Parse str1) / 100) * 100
let f = Int32.Parse str2
let r = n % f
match r with
  | 0 -> Console.WriteLine("00")
  | _ ->
    let x = f-r
    printfn "%02d" x

