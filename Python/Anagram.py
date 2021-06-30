def is_anagram(firstWord: str, secondWord: str) -> bool:
    if(len(firstWord) != len(secondWord)):
        return False

    buchstabenf = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    buchstabens = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

    for i in range(0,len(firstWord)):
        if(firstWord[i] =='a'):
            buchstabenf[0] += 1
        elif(firstWord[i] =='b'):
            buchstabenf[1] += 1
        elif(firstWord[i] =='c'):
            buchstabenf[2] += 1
        elif(firstWord[i] =='d'):
            buchstabenf[3] += 1
        elif(firstWord[i] =='e'):
            buchstabenf[4] += 1
        elif(firstWord[i] =='f'):
            buchstabenf[5] += 1
        elif(firstWord[i] =='g'):
            buchstabenf[6] += 1
        elif(firstWord[i] =='h'):
            buchstabenf[7] += 1
        elif(firstWord[i] =='i'):
            buchstabenf[8] += 1
        elif(firstWord[i] =='j'):
            buchstabenf[9] += 1
        elif(firstWord[i] =='k'):
            buchstabenf[10] += 1
        elif(firstWord[i] =='l'):
            buchstabenf[11] += 1
        elif(firstWord[i] =='m'):
            buchstabenf[12] += 1
        elif(firstWord[i] =='n'):
            buchstabenf[13] += 1
        elif(firstWord[i] =='o'):
            buchstabenf[14] += 1
        elif(firstWord[i] =='p'):
            buchstabenf[15] += 1
        elif(firstWord[i] =='q'):
            buchstabenf[16] += 1
        elif(firstWord[i] =='r'):
            buchstabenf[17] += 1
        elif(firstWord[i] =='s'):
            buchstabenf[18] += 1
        elif(firstWord[i] =='t'):
            buchstabenf[19] += 1
        elif(firstWord[i] =='u'):
            buchstabenf[20] += 1
        elif(firstWord[i] =='v'):
            buchstabenf[21] += 1
        elif(firstWord[i] =='w'):
            buchstabenf[22] += 1
        elif(firstWord[i] =='x'):
            buchstabenf[23] += 1
        elif(firstWord[i] =='y'):
            buchstabenf[24] += 1
        elif(firstWord[i] =='z'):
            buchstabenf[25] += 1

        #Second Word
    for z in range(0,len(secondWord)):
        if(secondWord[z] =='a'):
            buchstabens[0] += 1
        elif(secondWord[z] =='b'):
            buchstabens[1] += 1
        elif(secondWord[z] =='c'):
            buchstabens[2] += 1
        elif(secondWord[z] =='d'):
            buchstabens[3] += 1
        elif(secondWord[z] =='e'):
            buchstabens[4] += 1
        elif(secondWord[z] =='f'):
            buchstabens[5] += 1
        elif(secondWord[z] =='g'):
            buchstabens[6] += 1
        elif(secondWord[z] =='h'):
            buchstabens[7] += 1
        elif(secondWord[z] =='i'):
            buchstabens[8] += 1
        elif(secondWord[z] =='j'):
            buchstabens[9] += 1
        elif(secondWord[z] =='k'):
            buchstabens[10] += 1
        elif(secondWord[z] =='l'):
            buchstabens[11] += 1
        elif(secondWord[z] =='m'):
            buchstabens[12] += 1
        elif(secondWord[z] =='n'):
            buchstabens[13] += 1
        elif(secondWord[z] =='o'):
            buchstabens[14] += 1
        elif(secondWord[z] =='p'):
            buchstabens[15] += 1
        elif(secondWord[z] =='q'):
            buchstabens[16] += 1
        elif(secondWord[z] =='r'):
            buchstabens[17] += 1
        elif(secondWord[z] =='s'):
            buchstabens[18] += 1
        elif(secondWord[z] =='t'):
            buchstabens[19] += 1
        elif(secondWord[z] =='u'):
            buchstabens[20] += 1
        elif(secondWord[z] =='v'):
            buchstabens[21] += 1
        elif(secondWord[z] =='w'):
            buchstabens[22] += 1
        elif(secondWord[z] =='x'):
            buchstabens[23] += 1
        elif(secondWord[z] =='y'):
            buchstabens[24] += 1
        elif(secondWord[z] =='z'):
            buchstabens[25] += 1

    for i in range(0,25):
        if(buchstabenf[i] != buchstabens[i]):
            print(i+1)
            return False
    return True

print(is_anagram("lager","regal"))