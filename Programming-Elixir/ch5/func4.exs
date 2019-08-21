prefix = fn 
  x -> (fn y -> x <> " " <> y end)
end 


IO.inspect(prefix.("Yam").("Houston"))
