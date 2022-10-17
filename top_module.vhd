library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity top_module is
  Port( clk_100: in std_logic;
        echo : in STD_LOGIC;
        trigger : out STD_LOGIC;
        stop_hcsr : in STD_LOGIC;
        reset_hcsr: in std_logic;
        stop_servo: in std_logic;
        reset_servo: in std_logic;
        servo: out std_logic;
        vga_hs, vga_vs: out std_logic;
        vga_r, vga_g, vga_b: out std_logic_vector(3 downto 0));
end top_module;

architecture Behavioral of top_module is
signal clk_25 : std_logic;
signal clk_64 : std_logic;
signal for_vga_00, for_vga_01, for_vga_10, for_vga_11 : integer;
signal sw_hcsr_00, sw_hcsr_01, sw_hcsr_10, sw_hcsr_11 : std_logic;
signal greaterthan: std_logic_vector(1 downto 0);
signal output: std_logic_vector(4 downto 0);

component vga_clk is
  Port(clk_in : in STD_LOGIC;
      clk_out : out STD_LOGIC);
      end component;
      component proximity is
      Port(clk : in STD_LOGIC;
      echo : in STD_LOGIC;
      trigger : out STD_LOGIC;
      stop: in STD_LOGIC;
      button: in std_logic;
      sw_00, sw_01, sw_10, sw_11 : in std_logic;
      for_vga_00, for_vga_01, for_vga_10, for_vga_11 : out integer) ;
end component;

component vga
  Port(clk_25: in std_logic;
      h_out, v_out: out std_logic;
      bridge: in std_logic_vector (4 downto 0);
      compare: in std_logic_vector(1 downto 0);
      from_hcsr_00, from_hcsr_01, from_hcsr_10, from_hcsr_11 : in integer;
      R,G,B: out std_logic_vector(3 downto 0));
end component;

component bridge
  Port(output: out std_logic_vector(4 downto 0);
      from_hcsr_00, from_hcsr_01, from_hcsr_10, from_hcsr_11 : in integer;
      greaterthan: inout std_logic_vector(1 downto 0));
end component;

component servo_clk
  Port (clk_in : in STD_LOGIC;
        stop: in STD_LOGIC;
        clk_out: out STD_LOGIC);
end component;

component servo_pos
  Port (clk : in STD_LOGIC;
        stop : in STD_LOGIC;
        button : in std_logic;
        sw_hcsr_00, sw_hcsr_01, sw_hcsr_10, sw_hcsr_11 : out std_logic;
        servo : out STD_LOGIC);
end component;

begin
clk_servo: servo_clk port map(
  clk_in => clk_100,
  stop => stop_servo,
  clk_out => clk_64);

servo_code: servo_pos port map(
  clk => clk_64,
  stop => stop_servo,
  button => reset_servo,
  sw_hcsr_00 => sw_hcsr_00,
  sw_hcsr_01 => sw_hcsr_01,
  sw_hcsr_10 => sw_hcsr_10,
  sw_hcsr_11 => sw_hcsr_11,
  servo => servo);

kopru: bridge port map(
  output => output,
  from_hcsr_00 => for_vga_00,
  from_hcsr_01 => for_vga_01,
  from_hcsr_10 => for_vga_10,
  from_hcsr_11 => for_vga_11,
  greaterthan => greaterthan);

vga_code: vga port map(
  clk_25 => clk_25,
  h_out => vga_hs,
  v_out => vga_vs,
  bridge => output,
  compare => greaterthan,
  from_hcsr_00 => for_vga_00,
  from_hcsr_01 => for_vga_01,
  from_hcsr_10 => for_vga_10,
  from_hcsr_11 => for_vga_11,
  R => vga_r,
  G => vga_g,
  B => vga_b);

clk_vga: vga_clk port map(
  clk_in => clk_100,
  clk_out => clk_25);

hcsr: proximity port map(
  clk => clk_100,
  echo => echo,
  trigger => trigger,
  stop => stop_hcsr,
  button => reset_hcsr,
  sw_00 => sw_hcsr_00,
  sw_01 => sw_hcsr_01,
  sw_10 => sw_hcsr_10,
  sw_11 => sw_hcsr_11,
  for_vga_00 => for_vga_00,
  for_vga_01 => for_vga_01,
  for_vga_10 => for_vga_10,
  for_vga_11 => for_vga_11);

end Behavioral;

