=begin
  Lauren Vogel

 Practicing ruby basics by re-creating the
 hashtag assignment done in C.

 The purpose of this program is to check an input to see if it
 is a valid hashtag STARTING with the '#' character first, and
 contains only letters, numbers, and underscores, no other
 special characters can be in the input. The program will print
 whether the hashtag is valued or not before ending.

=end

#!/usr/bin/env ruby

puts "Check hashtag: "
hashtag = gets.chomp
#hashtag = hashtag.split("")

if hashtag[0] != '#'
  puts "Not a hashtag, missing '#'."
end

hashtag.each_char{ |c|
  #Regular expressionssss
  #\w is equivalent to [0-9a-zA-Z_]
  #\d is the same as [0-9]
  #\s matches white space (tabs, regular space, newline)
  #
  #There is also the negative form of these:
  #\W anything that’s not in [0-9a-zA-Z_]
  #\D anything that’s not a number
  #\S anything that’s not a space
  if c == "#" || c == "_" || c.match?(/\w/)
    next
  else
    return puts "Invalid hashtag containing illegal characters."
  end
}

puts hashtag + " is valid"
