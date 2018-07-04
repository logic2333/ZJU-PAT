str1 = input(); str2 = input(); str3 = input(); str4 = input()
#str1 = "3485djDkxh4hhGE"
#str2 = "2984akDfkkkkggEdsb"
#str3 = "s&hgsfdk"
#str4 = "d&Hyscvnm"
ipt = (str1, str2, str3, str4)
shorter = str1
if len(str2) < len(str1):
    shorter = str2
day = h = m = 0
findday = False
for i in range(0, len(shorter)):
    if (not findday) and str1[i].isupper() and str2[i] == str1[i]:
        day = ord(str1[i]) - ord('A') + 1
        findday = True
    if findday:
        if str1[i] == str2[i]:
            if str1[i].isdigit():
                h = int(str1[i])
            elif str1[i].isupper():
                h = ord(str1[i]) - ord('A') + 10
shorter = str3
if len(str4) < len(str3):
    shorter = str4
for i in range(0, len(shorter)):
    if str3[i].isalpha() and str3[i] == str4[i]:
         m = i
         break
dic = { 1 : "MON", 2 : "TUE", 3 : "WED", 4 : "THU", 5 : "FRI", 6 : "SAT", 7 : "SUN" }
print(dic[day], "{:0>2}".format(h), end = ':')
print("{:0>2}".format(m))
