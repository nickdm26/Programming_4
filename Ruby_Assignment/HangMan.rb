#This method takes a string argument and returns a boolean.
#Will return true if the argument lookAtLetter matches the regular expression otherwise it will return false.
def letterCheck(lookAtLetter)	#def is used to declare a method.
	lookAHead = lookAtLetter =~ /[[:alpha:]]/	#Saves the conditonal result as lookAHead. The conditonal result is the result of comparing lookAtLetter to the regular expression using the =~ operatotor. Return does not need to be written as the value if the last expression is automatically returned.
end	#The end of the letterCheck method.

#This method takes a argument and checks if it is equal to the key press 1.
#If the key 1 was pressed then the command prompt is cleared and the program exists.
#This method is simply used to close the program whenever the user wants.
def shouldQuit(input)	#def is used to declare a method.
	if(input == "1")	#Checks if the input variable is equal to the string 1.
		system "cls"	#If the input is true the command prompt is cleared.
		exit(0)			#The program will exit and return a success code.
	end		#The end of the if statement
end	#The end of the shouldQuit method.

#This method is used to print the contents of the word that the user has correctly guessed.
#If they have not guessed a letter then it will print a placeholder character in its place.
def displayWord			#def is used to declare a method, Parentheses do not need to be used if a method takes no arguments. 
	$ranWordBool.each_index do |i|		#Much like a for loop, this loop iterates over each index in ranWordBool with each index being referred to as i.
		if($ranWordBool[i]) 			#Checks if the value of ranWordBool is true
			print $ranWordArray[i]		#If that value is true then it prints the letter which is in the exact same postion from ranWordArray.
			$isWin += 1					#Incremeants isWin by 1, this is latter used to see if all the letters in the random word have been correctly guessed.
		else
			print "_"		#If the value of ranWordBool[i] is not true then it prints the placeholder character which is "_".
		end				#The end of the if else statement
	end			#The end of the each_index loop.
end			#The end of the displayWord method.

#The gameLoop method holds the bulk of the logic for the game.
#It Prints the various user interface text. It also keeps track of amount of turns that the user has left to win or lose the game.
#The game loop has a array which keeps track of the letters which have been used that are not within the word.
#It also reads in input from the user and then checks if that is a valid letter, if not it says Not a Letter, if more then 1 character is entered then it says Please enter 1 letter.
#If the letter is valid and not part of the word then it is stored in the lettersUsed array which is displayed so a user can see what they have entered.
def gameLoop		#def is used to declare a method, Parentheses do not need to be used if a method takes no arguments. 
	puts "1: Quit"		#Prints the text to the screen, The puts command also adds a new line character to the end of the string so the next text will be displayed on a line below it.
	turns = 10			#A constant number used to store the amount of turns the user has to win the game.
	turnsLeft = 0		#Turnsleft is increamted when a valid letter is entered that does not appear in the word.
	lettersUsed = []	#The lettersUsed array is declared so that each time the gameLoop is called it starts empty.
	while(turnsLeft < turns)		#While loop is used to run when the user has made less then 10 guesses, If it ends then they lose.
		$isWin = 0					#isWin is set to 0, When it reaches the length of the word then the user has won the game.
		displayWord					#The displayWord method is called to display the contents of the word the user has guessed.
		
		if($isWin == $ranWordBool.length)			#This if statement is used to check if isWin is equal to the length of the word. If it is then the game is won.
			system "cls"							#The command prompt is cleared so all the text does not stack.
			puts "1: Quit"							#Prints the text to the screen, The puts command also adds a new line character to the end of the string so the next text will be displayed on a line below it.
			puts "The word is #{$ranWord} and You Win"	#Displays the message and the word you correctly guessed when won.
			puts "Press any key to continue"		#Tells the user to hit a key to continue the game.
			return				#Uses return so that it may exit the gameLoop and start a new round.
		end			#The end of the if statement
		
		print "\n" + "Letters Used: "			#uses the new line character to display the text on a new line because print does not.
		lettersUsed.each_index do |looper|		#Much like a for loop, this loop iterates over each index in lettersUsed with each index being referred to as looper.
			print " #{lettersUsed[looper]} "	#displays the letters in the lettersUsed array to the screen, uses print insead of puts so that they are on the same line instead of a line each.
		end					#The end of the each_index loop
		puts "\n" + "Turns left: #{turns - turnsLeft}"  #Displays the text on a new line with the "\n" character, Prints the turns that the user has left to win the game or lose.
		
		puts "Enter a letter"		#Asks the user to enter a letter for the game to process.
		input = gets.chomp			#the input from the keyboard is read in using gets, chomp is called on gets to get rid of the "\n" character. Saves the input from the user into a variable.
		shouldQuit(input)			#The method shouldQuit is called to check if the input entered was meant to quit the game.
		system "cls"				#The command prompt is cleared so it does not get over run with text.
		
		if(input.length != 1)			#If the input read in has more then 1 character then it displays a message and does nothing else.
			puts "Please enter 1 letter"	#Displays the message asking to only enter 1 letter.
		elsif(letterCheck(input))		#Else if the inputs only 1 character and matches the regular expression in the letterCheck method.
			if(lettersUsed.include?(input))			#Checks if the character inputted is within the letters already used.
				puts "#{input} already choosen"		#Tells the user that the character has already been used, no turn for this is used.
			elsif($ranWordArray.include?(input))	#Else if the character is within the word.
				$ranWordArray.each_index do |i|		#Much like a for loop, this loop iterates over each index in ranWordArray with each index being referred to as i.
					if(input == $ranWordArray[i])	#If the character entered is equal to the character at $ranWordArray[i]
						$ranWordBool[i] = true		#ranWordBool[i] is set to true because the character at that location in $ranWordArray is the same. Also used to display which letters in the word have been correctly guessed.
					end			#The end of the if statement
				end			#The end of the each_index statement
			else
				lettersUsed << input		#If the character inputted has not been used before and is not in the word then that character is added to the end of the lettersUsed array. << is used to add onto the end of a array.
				turnsLeft += 1			#The amount of turnsLeft is increamted because the user guessed a incorrect letter.
			end					#The end of the if else statement
		else
			puts "Not a letter"		#If the character inputted fails letterChecks regular expression then it is not a letter and a message is displayed.
		end					#The end of the if else statement.
		puts "1: Quit"			#Prints a message to the screen telling the user the key to press to quit the game.
	end							#The end of the while loop
	puts "You lose"				#If the while loop exits because it ran out of turns the it displays the Lose text.
	puts "The word was #{$ranWord}"		#Displays the word that the user ran out of guesses on and lost.
	puts "Press any key to continue"	#Tells the user to hit a key to continue the game.
end			#The end of the gameLoop method

#Reads in a file and then loops through and saves each line into a array of string called words.
words = []			#Declares a array of of String which is going to be filled with words from a file
File.foreach('hangmanWords.txt') do |line| 		#Opens a file and then loops over each line in the file. That current line in the file can be reffered to as line.
	words << line.chomp				#Adds the current line into the words array. It uses the << to add onto the end of a array which means i dont need to keep track of the size. Chomp is used to remove the new line character from the string.
end			#end is used to close off the foreach loop much like {} are used in Java and C++

#A while loop holding true is used to create a infinte loop to run infinte rounds of the game.
#The user can quit the game at any time by pressing 1
#Randomly picks a word from the words array to use for the round, Then breaks that up and stores it as a array holding each letter.
#Once the array of letters is created a array of booleans the exact same size as the ranWordBool array is created and filled with false.
#The ranWordArray is used to keep track of which letters are in the word. The ranWordBool array is used to keep track of which letters are going to be shown to the user.
while(true)
	$ranWord = words[rand(words.length) + 1]	#rand is used to create a random number, by passing in words.length and adding 1 to the random number you can randomly seclect a word from the words array. Using the generated random number it uses that number as the index to assign the word to ranWord.
	$ranWordArray = $ranWord.chars				#Converts a string into a array and saves it as $ranWordArray. This is done so that it can check if a letter is part of the the word by checking if its in $ranWordArray.
	$ranWordBool = []							#Declares a empty array so that it will not cause issues when a new round starts.
	$ranWordArray.each_index do |i|				#much like a for loop, this loop iterates over each index in ranWordArray with each index being referred to as i. This loop is used to fill ranWordBool each index with false so its the exact same size as ranWordArray.
		$ranWordBool[i] = false			#Assigns each index in $ranWordBool to be equal to false. This represents if a letter in a word has been guessed correctly and should be shown to the user.
	end			#The end of the loop

	system "cls"			#Clears the Command prompt so that it is empty before the game starts displaying text.
	gameLoop				#Calls the gameLoop method. Parentheses do not need to be used if a method takes no arguments. 
	input = gets.chomp		#Waits and reads in text from the keybeoard and gets rid of the new line character
	shouldQuit(input)		#Calls shouldQuit while passing in the input to quit the program if the correct input is passed in.
end			#The end of the while loop.