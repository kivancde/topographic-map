library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity servo_clk is
  Port (clk_in : in STD_LOGIC;
        stop: in STD_LOGIC;
        clk_out: out STD_LOGIC);
end servo_clk;

architecture Behavioral of servo_clk is
signal clk_temp: STD_LOGIC;
signal clk_count : integer range 0 to 780 := 0;

begin
  freq_divider: process (stop, clk_in) begin
    if (stop = '1') then
      clk_temp <= '0';
      clk_count <= 0;
    elsif rising_edge(clk_in) then
      if (clk_count = 780) then
      clk_temp <= NOT(clk_temp);
      clk_count <= 0;
      else
      clk_count <= clk_count + 1;
      end if;
    end if;
end process;
clk_out <= clk_temp;
end Behavioral;
