import 'dart:collection';

import 'dart:math';

const ee = 2.718281828;
const pai = 3.141592653;

bool isDigit(String s) {
  return int.tryParse(s) != null;
}

class Stack<T> {
  final _stack = Queue<T>();

  void push(T element) {
    _stack.addLast(element);
  }

  T pop() {
    final T lastElement = _stack.last;
    _stack.removeLast();
    return lastElement;
  }

  T top() {
    return _stack.last;
  }

  void clear() {
    _stack.clear();
  }

  bool get isempty => _stack.isEmpty;
}

int precedence(var op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

double applyOp(double a, double b, var op) {
  switch (op) {
    case '+':
      return a + b;

    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
  }
  return 0;
}

double evaluate(String tokens) {
  int i;

  Stack<double> values = new Stack<double>();

  Stack<String> ops = new Stack<String>();

  for (i = 0; i < tokens.length; i++) {
    if (tokens[i] == ' ')
      continue;
    else if (tokens[i] == '(') {
      ops.push(tokens[i]);
    } else if (isDigit(tokens[i])) {
      double val = 0;

      while (i < tokens.length && isDigit(tokens[i])) {
        val = (val * 10) + (int.parse(tokens[i]));
        i++;
      }

      values.push(val);

      i--;
    } else if (tokens[i] == ')') {
      while (!ops.isempty && ops.top() != '(') {
        double val2 = double.parse(values.top().toString());
        values.pop();

        double val1 = double.parse(values.top().toString());
        values.pop();

        String op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
      }

      if (!ops.isempty) ops.pop();
    } else {
      while (!ops.isempty && precedence(ops.top()) >= precedence(tokens[i])) {
        double val2 = double.parse(values.top().toString());
        values.pop();

        double val1 = double.parse(values.top().toString());
        values.pop();

        String op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
      }

      ops.push(tokens[i]);
    }
  }

  while (!ops.isempty) {
    double val2 = double.parse(values.top().toString());
    values.pop();

    double val1 = double.parse(values.top().toString());
    values.pop();

    String op = ops.top();
    ops.pop();

    values.push(applyOp(val1, val2, op));
  }

  return values.top();
}

void calculatex(String str) {
  int ans = 0, temp = 0;
  for (int i = 0; i < str.length; i++) {
    if (str[i] == '1') temp = int.parse(str[i]);
    if (str[i] == '0') temp = int.parse(str[i]);
    if (str[i] == '+') {
      ans += temp + int.parse(str[i + 1]);
      i++;
    }
  }
  print(ans);
}

void main() {
  String str;
  print(evaluate("98/6*6-(56+32*(54-65))/6+325-65"));
  print(log(ee).ceilToDouble());
}
