help = system("../ranqo", "-h");
quote = system("../ranqo", "test.rqo");
helpAgain = system("../ranqo", "test.rqo", "-h");
list = system("../ranqo", "test.rqo", "-l");
amount = system("../ranqo", "test.rqo", "-amt");
specific = system("../ranqo", "test.rqo", "-s", "3");
find = system("../ranqo", "test.rqo", "-f", "cool");
add = system("../ranqo", "test.rqo", "-a", "yay");
remove = system("../ranqo", "test.rqo", "-r", "yay");
addList = system("../ranqo", "test.rqo", "-al", "yay");
removeList = system("../ranqo", "test.rqo", "-rl", "yay");

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