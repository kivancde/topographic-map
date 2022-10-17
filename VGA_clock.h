library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity vga_clk is
port ( clk_in : in STD_LOGIC;
      clk_out : out STD_LOGIC);
end vga_clk;

Architecture Behavioral of vga_clk is
signal clk_temp : std_logic := '0';

begin
clk_out <= clk_temp;
process (clk_in)
variable counter : integer := 0;
begin
if (rising_edge(clk_in)) then
  if (counter < 1) then
    counter := counter + 1;
  else
    counter := 0;
    clk_temp <= not clk_temp;
  end if;
end if;
end process;
end Behavioral;
