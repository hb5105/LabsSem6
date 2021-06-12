from operator import itemgetter
import sys
current_word = None
current_count = 0
max=0;
word = None
for line in sys.stdin:
	line = line.strip()
	word, count = line.split(' ', 1)
	try:
		count = int(count)
	except ValueError:
		# count was not a number, so silently
		# ignore/discard this line
		continue

	# this IF-switch only works because Hadoop sorts map output
	# by key (here: word) before it is passed to the reducer
	if current_word == word:
		current_count += count
	else:
		if current_word:
			# write result to STDOUT
			print (current_word,current_count)
		current_count = count
		current_word = word
		if(current_count>max):
			max=current_count
			mw=current_word

# do not forget to output the last word if needed!
if current_word == word:
	print (current_word,current_count)
print("max frequency word:\t ",mw, "with count :",max)
