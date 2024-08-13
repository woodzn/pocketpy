exit()

from dataclasses import dataclass, asdict

@dataclass
class A:
    x: int
    y: str = '123'

assert repr(A(1)) == "A(x=1, y='123')"
assert repr(A(x=3)) == "A(x=3, y='123')"
assert repr(A(1, '555')) == "A(x=1, y='555')"
assert repr(A(x=7, y='555')) == "A(x=7, y='555')"

assert asdict(A(1, '555')) == {'x': 1, 'y': '555'}

assert A(1, 'N') == A(1, 'N')
assert A(1, 'N') != A(1, 'M')

