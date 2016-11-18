# Get My Number Game
# Written by nick
puts "Welcome to 'Get My Number!'"
puts "What's your name? "
input = gets
name = input.chomp
puts "Welcome, #{name}"

#Store a random num
puts "i've got a random number between 1 and 100."
puts "Can you guess it?"
target = rand(100) + 1
num_guesses = 0

guessed_it = false

until num_guesses == 10 || guessed_it
	puts "You have #{10 - num_guesses} guesses left."
	print "Make a guess: "
	guess = gets.to_i
	num_guesses += 1

	if guess < target
		puts "Too Low"
	elsif guess > target
		puts "Too High"
	elsif guess == target
		puts "Great #{name}!"
		puts "You guessed the number in #{num_guesses} guesses!"
		guessed_it= true
	end
end

unless guessed_it
	puts "Sorry. You didnt get my number. (It was #{target}.)"
end