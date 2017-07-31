# Lisp 之 根源

## 七个原始操作符

- `(quote x)` 返回 `x` <=> `'x`
  - `(quote a)`: `a`
  - `'a`: `a`
  - `(quote (a b c))`: `(a b c)`
- `(atom x)` 返回 `t` 如果 `x` 是一个原子或空表，否则返回 `()`
  - `(atom 'a)`: `t`
  - `(atom '(a b c))`: `()`
  - `(atom '())`: - `t`
  - 代码和数据由相同的数据结构构成，用 `quote` 区分
    - `(atom (atom 'a))`: `t`，通过 quote 一个表避免被求值，一个未被引用的表作为自变量传给 atom 将被视为代码
    - `(atom '(atom 'a))`: `()`，一个被 quote 的表仅被视为表
- `(eq x y)` 返回 t 如果 x 和 y 的值是同一个原子或都是空表，否则返回 ()
  - `(eq 'a 'a)`: t
  - `(eq 'a 'b)`: ()
  - `(eq '() '())`: t
- `(car x)` 期望的 x 的值是一个表并且返回 x 的第一个元素
  - `(car '(a b c))`: a
- `(cdr x)` 期望的 x 的值是一个表并且返回 x 的第一个元素之后的所有元素
  - `(cdr '(a b c))`: (b c)
- `(cons x y)` 期望 y 的值是一个表并且返回一个新表，它的第一个元素是 x 的值，后面跟着 y 的各个元素
  - `(cons 'a '(b c))`: (a b c)
  - `(cons 'a (cons 'b (cons 'c '())))`: (a b c)
  - `(cdr (cons 'a '(b c)))`: (b c)
- `(cond (p1 ... e1)...(pn ... en))` p 表达式依次求值直到有一个返回 t，如果能找到这样的 p 表达式，相应的 e 表达式的值作为整个 cond 表达式的返回值
  - `(cond ((eq 'a 'b) 'first) ((atom 'a) 'second))`: second

## 函数的表示



## 参考资料

- [Lisp- 【安装 SBCL 的图片教程】可以在 Windows 下运行的 Common Lisp 编译器（琪露诺才不是笨蛋！琪露诺也能看懂！） - 瑞兰德(rsreland)的日志 - 网易博客](http://blog.163.com/rs_reland/blog/static/138791295201211158192267/)
- [Lisp之根源](http://daiyuwen.freeshell.org/gb/rol/roots_of_lisp.html)
- [前言 — ANSI Common Lisp 中文版](http://acl.readthedocs.io/en/latest/zhCN/preface-cn.html)
