library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use ieee.std_logic_unsigned.all;

entity proximity is
Port (clk: in STD_LOGIC;
      echo: in STD_LOGIC;
      stop: in STD_LOGIC;
      button: in STD_LOGIC;
      trigger: out STD_LOGIC;
      sw_00, sw_01, sw_10, sw_11 : in std_logic;
      for_vga_00, for_vga_01, for_vga_10, for_vga_11 : out integer) ;
end proximity;

architecture Behavioral of proximity is
begin

process(clk, stop)
variable wait_info : STD_LOGIC:= '1';
variable timer_1: integer:=0;
variable timer_2: integer:=0;
variable timer_00: integer:=0;
variable timer_echo: integer:=0;
--variable c : std_logic_vector(1 downto 0);

begin
  if stop = '1' then
    elsif rising_edge(clk) then
      timer_1:= timer_1+1;
      timer_2:= timer_2+1;
      if(timer_1 = 0) then
        trigger <= '1';
      elsif(timer_1 = 12000000) then --0.5s (2400 => 10us)
        trigger <= '0';
        wait_info :='1';
      elsif(timer_1 = 24000000) then-- 2s
        timer_1:=0;
        trigger <= '1';
      end if;

    if (echo = '1') then
      timer_00 := timer_00+1;
    elsif(echo = '0' and wait_info ='1') then
      timer_echo := timer_00;
      timer_00 :=0;
      wait_info :='0';
    end if;

    if sw_00 = '1' then
      for_vga_00 <= timer_echo;
    elsif sw_01 = '1' then
      for_vga_01 <= timer_echo;
    elsif sw_10 = '1' then
      for_vga_10 <= timer_echo;
    elsif sw_11 = '1' then
      for_vga_11 <= timer_echo;
    end if;
  end if;
end process ;
end Behavioral;
