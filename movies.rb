#!/usr/bin/env ruby
=begin

  This is a little initial ruby learning file.

  This code has movie titles and movie ratings hard
coded into it and allows a user to add movies, update
movies, display current stored movies and rating, and
delete movies through terminal prompts.

=end
movies = {
  Memento: 3,
  Primer: 4,
  Ishtar: 1
}
puts "What would you like to do?"
puts "Type 'add' to add a movie."
puts "Type 'update' to update a movie."
puts "Type 'display' to display all movies."
puts "Type 'delete' to delete a movie."
choice = gets.chomp

case choice
  when "add"
    puts "give me the title"
    title = gets.chomp
    #if the movie already stored
    if movies[title.to_sym] != nil
      puts "already here nerd"
      return
    end
    puts "rating?"
    rating = gets.chomp
    movies[title.to_sym] = rating.to_i
    puts "added #{title}"

  when "update"
    puts "what the title of movie u wanna update?"
    title = gets.chomp
    #if that m ovie title cant be found
    if movies[title.to_sym] == nil
      puts "mmmm not real"
      return
    end
    puts "new rating?"
    rating = gets.chomp
    movies[title.to_sym] = rating.to_i
    puts "updated #{title}"

  when "display"
    movies.each { |m, r|
      puts "#{m}: #{r}"
    }

  when "delete"
    puts "who u want gone?"
    title = gets.chomp
    #if the movie title isnt found
    if movies[title.to_sym] == nil
      puts "already gone"
      return
    end
    movies.delete(title.to_sym)
    puts "#{title} is now gone"

  else
    puts "Error! u need to correctly enter one of the listed options"

end
