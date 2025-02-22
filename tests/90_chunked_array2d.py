import array2d
from linalg import vec2i


def on_builder(a:vec2i):
    return str(a)
    pass

default = 0
a = array2d.chunked_array2d(16, default,on_builder)
assert a.chunk_size == 16

a[vec2i(16, 16)] = 16
a[vec2i(15, 16)] = 15
assert a[vec2i(16, 16)] == 16
assert a[vec2i(15, 16)] == 15
assert a[vec2i(16, 15)] == default

a1,a2=a.world_to_chunk(vec2i(15,16))

assert a.remove_chunk(a1)== True
assert a[vec2i(15, 16)] == default

assert a.get_context(vec2i(1,1))==on_builder(vec2i(1,1))

assert a.view().tolist()==[
    [16 if i==0 and j==0 else 0 for j in range(16)] for i in range(16)
]
assert a.view_rect(vec2i(15,15),4,4).tolist()==[
    [0,0,0,0],
    [0,16,0,0],
    [0,0,0,0],
    [0,0,0,0]
]
a[vec2i(15, 16)] = 15
assert a.view_chunk(a1).tolist()==[
    [15 if i==0 and j==15 else 0 for j in range(16)] for i in range(16)
]
a.clear()

assert a[vec2i(16, 16)] == default
assert a[vec2i(15, 16)] == default
assert a[vec2i(16, 15)] == default
