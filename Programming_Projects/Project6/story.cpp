#include <iostream>

using namespace std;

void PrintIntro() {
    cout << "The Adventure of the 40-Acre Forest" << endl;
    cout << endl;
    cout << "In a quaint little town nestled in the heart of the mysterious 40-Acre Forest," << endl;
    cout << "lived a group of friends: Brayden, Kris, Jason, and you. They were known for their adventurous spirit," << endl;
    cout << "and it was this spirit that led them into a life-altering adventure." << endl;
    cout << endl;
    cout << "One gloomy evening, the group received a letter. It was penned by the renowned archaeologist," << endl;
    cout << "Professor Santacruz. The letter revealed that he had been working on a groundbreaking discovery," << endl;
    cout << "but now, he had vanished. He had left a cryptic message that hinted at a series of challenges" << endl;
    cout << "and asked for their help. Without hesitation, the four friends decided to embark on a quest" << endl; 
    cout << "to save Professor Santacruz." << endl;
    cout << endl;
}

void PrintTutorial() {
    cout << "Chapter 0: The Tutorial" << endl;
    cout << endl;
    cout << "'How does this even work?' You ask." << endl;
    cout << "'Have you never played a text-based adventure game before?' Kris replies." << endl;
    cout << "'Well, not like this. Didn't you make this two days ago?' You say." << endl;
    cout << "'Ok, fair.' Kris says. 'Here, we'll show you how to play and even some of our secrets." << endl;
    cout << endl;
    cout << "You are led to a bookshelf. The middle two shelves each have an array (get it?) of numbered books on them:" << endl << endl;
    cout << "[1 4 0 5 6 17 12 9 15]" << endl;
    cout << "[31 4 39 58 19 47 63 91 45 1 22]" << endl << endl;
    cout << "This is the secret entrance to the Professor's study, EER 3.812." << endl;
    cout << "To get in, you will need to use some magic to figure out the two magic numbers." << endl;
    cout << "The first magic number is the sum of the first shelf. The second magic number is the sum of the second shelf." << endl;
    cout << "However, the first shelf requires using a [1, N-1] decomposition, and the second shelf requires using a [N/2, N/2] decomposition." << endl;
    cout << "Write the functions sumNums1 and sumNums2 to help you find the magic numbers. Once you have found them using the correct method, you will be able to enter the study." << endl;
    cout << endl;
}

void PrintTutorialSumFailValue() {
    cout << "You try finding the sums but nothing happens." << endl;
    cout << "The TA's look at you quizically. Did you even pass M408C? You should try again." << endl;
    cout << endl;
}

void PrintTutorialSumFailCount() {
    cout << "You try finding the sums and get the correct values, but the method is wrong." << endl;
    cout << "That's the wrong spell, try using recursion!" << endl;
    cout << endl;
}

void PrintTutorialSumSuccess() {
    cout << "You find the correct sums and the bookshelf slides open. Who would have thought those were the magic numbers?" << endl;
    cout << "Well done. You and the TAs enter the study and begin to solve the mystery." << endl;
    cout << endl;
}

void PrintChapterOne() {
    cout << "Chapter 1: The Enigma of the Reversed Number" << endl;
    cout << endl;
    cout << "Their journey began at the professor's study. It was filled with dusty tomes about the ancient magic of C and C++." << endl;
    cout << "They discovered a cryptic note scrawled on the whiteboard that seemed to hint at an entrace to the secret tunnels below UT." << endl;
    cout << "Upon reaching the location described in the note, they found themselves block by a wall of speedway bricks." << endl;
    cout << "Kris, with his sharp intellect, notices a peculiar brick with a number written in reverse etched on it: \"20543\"" << endl;
    cout << "As the group examined the wall, they realized that it contained a sequence of numbers, but all in reverse order." << endl;
    cout << "Intrigued by the challenge, they knew they needed to decipher this cryptic message to continue their quest." << endl;
    cout << "The TA's turn to you, and ask you to write a recursive function reverse() that can reverse a positive N digit integer to solve the puzzle." << endl;
    cout << endl;
}

void PrintReverseFail() {
    cout << "After a long struggle, they realized that they had not successfully solved the puzzle" << endl;
    cout << "and were thus left to either fix their mistakes or start again completely." << endl;
    cout << endl;
}

void PrintReverseSuccess() {
    cout << "You all work together, trying to unravel the mystery of the reversed number." << endl;
    cout << "The group deciphers the sequence and uncovers the brick that opens the door hidden within the wall" << endl;
    cout << "Inside, you find the first artifact, a key that would open the door to the next adventure." << endl;
    cout << "This key would be essential in unraveling the mysteries that lay ahead in their quest to save Professor Santacruz." << endl;
    cout << endl;
}

void PrintChapterTwo() {
    cout << "Chapter 2: The Legend of the Linked Ladder" << endl;
    cout << endl;
    cout << "Their next clue led them to the UT Tower, where legends whispered of a levitating ladder of stairs that leads to the top floor." << endl;
    cout << "After a long climb to the 27th floor, the key began to glow, and revealed the entrance to the never-before-seen levitating staircase" << endl;
    cout << "Originally created long ago by the ancient UT students, some of the stairs were cracked and had been marked by previous adventurers with a large 'X'." << endl;
    cout << "The group realized that they would need to find a way to avoid the broken stairs, or else they would fall to their doom." << endl;
    cout << "It was up to you to use your powers of recursion to conjure removeList() to create a linked-list of the usable steps of the staircase." << endl;
    cout << endl;
}

void PrintRemoveFail() {
    cout << "The group was unable to find a way to avoid the broken stairs, and fell to their doom." << endl;
    cout << endl;
}

void PrintRemoveSuccess() {
    cout << "You meticulously map out a safe route to climb the staircase." << endl;
    cout << "The group climbs the staircase and reaches the top floor, where they find the next artifact." << endl;
    cout << "It was a bracelet of connected beads with letters engraved on each bead that made a cryptic message that hinted at their next destination." << endl;
    cout << endl;
}

void PrintChapterThree() {
    cout << "Chapter 3: The Weighty Conundrum at the Elemental Fountain" << endl;
    cout << endl;
    cout << "Their next challenge awaited them at the Elemental Fountain, a mystical fountain at the heart of campus with a single gigantic glass scale that towered over the surrounding landscape." << endl;
    cout << "It stood as an enigmatic sentinel, guarding the secrets of the campus." << endl;
    cout << "Beside the scale lay a knapsack with various objects they were to use including items such as stones, gems, etc. The inscription on the pedestal read: \"To proceed, place the maximum weight on the scale without shattering it.\"" << endl;
    cout << "Brayden, Kris, Jason, and you contemplated their options. They knew that they needed to pile on as many items as possible to tip the scale in their favor." << endl;
    cout << "The challenge was knapsack(), to carefully select the right combination of objects to achieve the heaviest weight without going over the limit." << endl;
    cout << endl;
}

void PrintWeightFail() {
    cout << "They watched in suspense as the scale shot the items around the area as they had not had the correct combination of weights. They were forced to try again… maybe trying different items." << endl;
    cout << endl;
}

void PrintWeightSuccess() {
    cout << "After several attempts and moments of suspense, they finally managed to achieve the maximum weight the scale could bear. A triumphant chime resonated through the springs, signaling their success." << endl;
    cout << "With the fourth artifact was a magnificent amulet. The Amulet was adorned with symbols representing each of the four elements. They were on to their next test." << endl;
    cout << endl;
}

void PrintChapterFour() {
    cout << "Chapter 4: The Labyrinth of Infinite Forks";
    cout << endl;
    cout << "Their next challenge led them to a perplexing place known as The Labyrinth. In the heart of the Whispering Pines, they found themselves standing before a bewildering array of doors, each identical in appearance." << endl;
    cout << "The enigmatic inscription on the ancient pedestal read: \"To proceed, you must find the shortest path through the doors. One door leads to another, and another, until you reach the end.\"" << endl;
    cout << "The group looked at the labyrinthine arrangement of doors and realized that the puzzle was to find the most direct route to reach the final door. " << endl;
    cout << "As they opened the first door, they were met with a forking path that led to another, and then another, leading them to a seemingly endless path through the interconnected doors." << endl;
    cout << "You realized that you would need to write lease_weight_path() to find the shortest path through the labyrinth to reach the final door." << endl;
    cout << endl;
}

void PrintTreeFail() {
    cout << "They thought they had found the end, but it wasn’t correct. Too many doors were opened and they were forced back to the beginning. How many times were they going to have to try again?" << endl;
    cout << endl;
}

void PrintTreeSuccess() {
    cout << "After what felt like an eternity of exploration and choice-making, they finally emerged from the labyrinth into open space. They had found the shortest path through the intricate puzzle." << endl;
    cout << "The fourth artifact awaited them and was an ornate key… how fitting after the challenge they had just completed." << endl;
    cout << endl;
}

void PrintConclusion() {
    cout << "Armed with the wisdom, strength, and knowledge they had gained through their journey, Brayden, Kris, Jason, and you returned to the heart of the Forty-Acre Forest." << endl;
    cout << "The ancient trees stood tall, as if whispering words of encouragement, and the forest seemed to pulse with anticipation." << endl;
    cout << "With the accumulated artifacts and newfound insights, they discovered an ancient tree with a hollow trunk, its door hidden from sight." << endl;
    cout << "Using the key from the Elemental Fountain and the book from the Labyrinth, they unlocked the door. It opened to reveal a hidden passage that led them deep into the heart of the forest." << endl;
    cout << "The passage was a portal to a secret chamber where Professor Santacruz was held. The professor, weak but relieved, greeted them with gratitude and a tale of his own adventures and discoveries in the depths of the forest." << endl;
    cout << "As they freed him, they also learned the purpose of their quest - the ancient forest held the key to preserving the balance of nature and had the potential to unlock groundbreaking knowledge that could benefit all of humanity." << endl;
    cout << "The professor's research was intended to protect this delicate equilibrium." << endl;
    cout << "With the artifacts they had gathered and the wisdom they had acquired, Brayden, Kris, Jason, and you decided to carry on the professor's work." << endl;
    cout << "Together, they vowed to protect the forest's secrets and ensure that the knowledge they had gained would be used for the betterment of the world." << endl;
    cout << "As they exited the forest, the professor offered his heartfelt thanks and an understanding that some mysteries were meant to be preserved." << endl;
    cout << "Their adventure had not only saved the professor but had instilled in them a profound respect for the natural world and the knowledge hidden within it." << endl;
    cout << "The legend of their quest would live on, a testament to the power of courage, friendship, and the preservation of the forest's secrets. Their journey had concluded, but their commitment to safeguarding the forest's wisdom and maintaining the delicate balance of nature was just beginning." << endl;
    cout << "Before they parted ways, the professor offered them a final gift: a tic-tac-toe board. Why you may ask? Well that was a story for another time." << endl;
    cout << "The End." << endl;
    cout << endl;
}