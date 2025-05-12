struct Stack {
  unique_ptr<int[]> m_stack;
  int m_tos;
  size_t m_size;

  Stack() : m_stack(nullptr), m_tos(0), m_size(0) {}

  Stack(size_t size) : m_stack(new int[size]), m_tos(0), m_size(size) {}

  Stack &operator=(Stack &o) {
    m_stack.swap(o.m_stack);
    m_tos = o.m_tos;
    m_size = o.m_size;
    return *this;
  }

  bool push(const int &n) {
    if (m_tos == m_size) {
      return false;
    }
    m_stack[m_tos++] = n;
    return true;
  }
  bool pop(int &n) {
    if (m_tos == 0) {
      return false;
    }
    n = m_stack[--m_tos];
    return true;
  }
};

bool is_prime(int n) {
  if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
    return false;
  }

  int div{static_cast<int>(sqrt(n) + 1)};

  while (div > 7) {
    if (n % div == 0) {
      return false;
    }
    --div;
  }

  return true;
}

int next_prime(int n) {
  int p{n + 1};

  if (n < 2) {
    return 2;
  }

  if (n < 3) {
    return 3;
  }

  if (n < 5) {
    return 5;
  }

  if (n < 7) {
    return 7;
  }

  while (!is_prime(p)) {
    ++p;
  }

  return p;
}

vector<int> waiter(vector<int> number, int q) {
  vector<int> ans{};

  size_t n{number.size()};
  Stack a{n};
  Stack b{n};
  int s{};
  int p{};

  // push plates on A0
  for (const auto &n : number) {
    a.push(n);
  }

  for (int i{}; i < q; ++i) {
    Stack c{n};
    p = next_prime(p);

    while (a.pop(s)) {
      if (s % p == 0) {
        b.push(s); // Bi
      } else {
        c.push(s); // temp stack (Ai)
      }
    }
    a = c; // Ai

    // move Bi to ans
    while (b.pop(s)) {
      ans.push_back(s);
    }
  }
  while (a.pop(s)) {
    ans.push_back(s);
  }
  return ans;
}
0|Add CommentPermalink
