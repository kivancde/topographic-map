library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity servo_pos is
  PORT (clk: in STD_LOGIC;
      stop: in STD_LOGIC;
      button: in std_logic;
      sw_hcsr_00, sw_hcsr_01, sw_hcsr_10, sw_hcsr_11 : out std_logic;
      servo: out STD_LOGIC);
end servo_pos;

architecture Behavioral of servo_pos is
signal count : unsigned(10 downto 0);
signal pwm: unsigned(8 downto 0);
signal position: STD_LOGIC_VECTOR(7 downto 0);
signal timer: integer:=0;

begin
process (stop, clk)

begin
if stop = '1' then
  position <= "00000010";
elsif rising_edge(clk) then
  if timer > 300000 and button = '1' then
    timer <= 0;
  else
    timer <= timer+1;
    if timer< 100000 then
      position <= "00000001"; --0*
      sw_hcsr_00 <= '1';
      sw_hcsr_01 <= '0';
      sw_hcsr_10 <= '0';
      sw_hcsr_11 <= '0';
    elsif timer> 100000 and timer< 200000 then
      position <= "00010011"; --60*
      sw_hcsr_00 <= '0';
      sw_hcsr_01 <= '1';
      sw_hcsr_10 <= '0';
      sw_hcsr_11 <= '0';
    elsif timer> 200000 and timer< 300000 then
      position <= "00101011"; --120*
      sw_hcsr_00 <= '0';
      sw_hcsr_01 <= '0';
      sw_hcsr_10 <= '1';
      sw_hcsr_11 <= '0';
    elsif timer> 300000 then
      position <= "10000000"; --180*
      sw_hcsr_00 <= '0';
      sw_hcsr_01 <= '0';
      sw_hcsr_10 <= '0';
      sw_hcsr_11 <= '1';
    elsif timer> 400000 then
      sw_hcsr_11 <= '0';
    end if;
  end if;
pwm <= unsigned(position & '0') + 32;
end if;
end process;

servo <= '1' when (count < pwm) else '0';

counter: process (stop, clk)
begin
  if (stop = '1') then
    count <= (“00000000000”);
  elsif rising_edge(clk) then
    if (count = 1279) then
      count <= (“00000000000”);
    else
      count <= count + 1;
    end if;
  end if;
end process;
end Behavioral;
