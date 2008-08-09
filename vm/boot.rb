# String stuff
a = "ohaie"[0,2]
a += "aie".to_s
a += 1.to_s
a += true.to_s

# Conditional
if a
  Kernel.puts "a is a " + a.class.name
  Kernel.puts "a = " + a
end

# stdio
Kernel.puts "prog name: " + ARGV.last
Kernel.puts "type a key:"
Kernel.puts "you typed: " + STDIN.read(1)

# method
def method!(x); x end
Kernel.puts "method! returned: " + method!("var")

# class
class Poop
  def initialize
    @smell = "smell"
    @@answer = "yes"
  end
  def do_you_smell?
    "do you " + @smell + "? "
  end
  def answer
    @@answer
  end
end
p = Poop.new
Kernel.puts p.do_you_smell? + p.answer

# exception
Kernel.raise "This is not so exceptional"