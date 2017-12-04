Trie Node - A way of efficiently storing strings through n-array trees.
![alt text](https://cdn-images-1.medium.com/max/600/1*sZOrNXzlQICVv5ePpav1-g.jpeg)

What if we wanted to add the word pecked to this list of words represented by this trie? We’d need to do two things in order to make this happen:

First, we’d need to check that the word pecked doesn’t already exist in this trie.

Next, if we’ve traversed down the branch where this word ought to live and the words doesn’t exist yet, we’d insert a value into the node’s reference where the word should go. In this case, we’d insert e and d at the correct references.
