fizz = fn
  0, 0, _ -> "FizzBuzz"
  0, _, _ -> "Fizz"
  _, 0, _ -> "Buzz"
  _, _, third -> third
end

fb = fn 
  n -> fizz.(rem(n, 3), rem(n, 5), n)
end 


IO.inspect(fizz.(0, 0, "x"))
IO.inspect(fizz.(0, "a", "b"))
IO.inspect(fizz.("a", 0, "b"))
IO.inspect(fizz.("a", "b", "c"))


IO.inspect([fb.(10), fb.(11), fb.(12)])
