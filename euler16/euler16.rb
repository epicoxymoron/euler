# Title: Power digit sum
# 
# Problem #: 16
# 
# Description: 2**15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
# 
# What is the sum of the digits of the number 21000?
# 
# Author: epicoxymoron
# Language: Ruby 1.9

# Sum up the digits of a number
#
# * *Args*    :
#   - +number+ -> the number
# * *Returns* :
#   - the sum of each digit in the number
def sum_digits(number)
  s = 0
  number.to_s.split("").each {|c| s += c.to_i}
  s
end

if __FILE__ == $PROGRAM_NAME
  puts sum_digits 2**1000
end
