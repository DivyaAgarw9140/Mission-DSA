std::string highestValuePalindrome(std::string s, int k) {
  auto alreadyPalindrome = 0;
  auto halfSize = s.size() / 2;
  for (auto it = s.begin(), it2 = prev(s.end()); it < it2; ++it, --it2) {
    if (*it == *it2) {
      ++alreadyPalindrome;
    }
  }
  // This is the minimum changes to make in the first half to make it palindrome
  auto requiredChanges = halfSize - alreadyPalindrome;
  // This is the number of extra changes I can make in the first half after making it a palindrome
  auto spareChanges = k - requiredChanges; 
  for (auto it = s.begin(), it2 = prev(s.end()); it < it2; ++it, --it2) 
  {
    // Letters are different, let's change that
    if (*it != *it2) 
    {
      // If none are nine, and I have a spare change, I can make this one a '9'
      if ((spareChanges > 0) && (*it != '9') && (*it2 != '9')) 
      {
        *it = '9';
        --spareChanges;
        --k;
      }
      // And now, either the left or the right will change to the highest value of the two...
      *it = *it2 = std::max(*it, *it2);
      --k;
    }
	// Both letters are the same, but they are not nine, and I have Ks to make them 9
    else if ((spareChanges >= 2) && (*it != '9')) 
    {
      *it = *it2 = '9';
      spareChanges -= 2;
      k -= 2;
    }
  }

  // So the letter is a palindrome...
  // If I have an extra k, I will use one to move the middle letter to 9, if it is odd ...
  if ((k > 0) && (s.size() % 2 == 1)) {
    s[s.size() / 2] = '9';
  }

  if (k < 0) {
    return "-1";
  }

  return s;
}
