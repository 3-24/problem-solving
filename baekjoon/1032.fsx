open System

let rec getStrs n li =
    if (n = 0) then li else
      let str = Console.ReadLine()
      getStrs (n-1) (str::li)

let rec getPattern (strs:list<String>) (x:Int32) (length:Int32) (result:String) = 
  let rec isCommon (strs:list<String>) idx c =
    match strs with
    | hd :: tl -> 
      if (hd.[x] = c) then isCommon tl x c else '?'
    | [] -> c
  if (x = length) then result else
    let c = (List.head strs).[x]
    let newresult = result + string (isCommon strs x c)
    getPattern strs (x+1) length newresult
    

let n = Console.ReadLine() |> Int32.Parse
let strs = getStrs n []
let l = strs |> List.head |> String.length
getPattern strs 0 l "" |> printfn "%s"
