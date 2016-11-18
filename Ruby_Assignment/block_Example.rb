def twice(&my_block)
	puts "In The method, about to call the block!"
	my_block.call
	puts "Back in the method, about to call the block again!"
	my_block.call
	puts "Back in the method, about to return!"
end

twice do
	puts "Woooooo!"
end