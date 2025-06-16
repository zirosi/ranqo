help = system("../ranqo", "-h");
system("clear")
quote = system("../ranqo", "test.rqo");
system("clear")
helpAgain = system("../ranqo", "test.rqo", "-h");
system("clear")
list = system("../ranqo", "test.rqo", "-l");
system("clear")
amount = system("../ranqo", "test.rqo", "-amt");
system("clear")
specific = system("../ranqo", "test.rqo", "-s", "3");
system("clear")
find = system("../ranqo", "test.rqo", "-f", "cool");
system("clear")
add = system("../ranqo", "test.rqo", "-a", "yay");
system("clear")
remove = system("../ranqo", "test.rqo", "-r", "yay");
system("clear")
addList = system("../ranqo", "test.rqo", "-al", "yay");
system("clear")
removeList = system("../ranqo", "test.rqo", "-rl", "yay");
system("clear")

if help == false
  puts "The Help command Failed";
end
if quote == false
  puts "Random Quote Failed";
end
if helpAgain == false
  puts "The Help command Failed";
end
if list == false
  puts "List command Failed";
end
if amount == false
  puts "Amount command Failed";
end
if specific == false
  puts "Specific command Failed";
end
if find == false
  puts "Find command Failed";
end
if add == false
  puts "Add command Failed";
end
if remove == false
  puts "Remove command Failed";
end
if addList == false
  puts "Add List command Failed";
end
if removeList == false
  puts "Remove List command Failed";
end