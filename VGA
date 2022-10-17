library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity vga is
Port(clk_25: in std_logic;
      h_out, v_out: out std_logic;
      from_hcsr_00, from_hcsr_01, from_hcsr_10, from_hcsr_11 : in integer;
      bridge : in std_logic_vector(4 downto 0);
      compare: in std_logic_vector(1 downto 0);
      R,G,B: out std_logic_vector(3 downto 0));
end vga;

architecture Behavioral of vga is
signal hpos: integer range 0 to 799 :=0;
signal vpos: integer range 0 to 524 :=0;
begin

process(clk_25)
begin

if (rising_edge(clk_25)) then
  if (hpos < 410 and hpos > 170 and vpos < 275 and vpos > 55) then
    if from_hcsr_00< 34800 then
      R <= "1111";
      G <= "0000";
      B <= "0000"; --RED
    elsif from_hcsr_00< 69600 and from_hcsr_00> 34800 then
      R <= "1000";
      G <= "0010";
      B <= "0011"; --BROWN
    elsif from_hcsr_00< 104400 and from_hcsr_00> 69600 then
      R <= "1111";
      G <= "1111";
      B <= "0010"; --YELLOW
    elsif from_hcsr_00< 150800 and from_hcsr_00> 104400 then
      R <= "0000";
      G <= "1110";
      B <= "0000"; --GREEN
    elsif from_hcsr_00> 150800 then
      R <= "0000";
      G <= "0111";
      B <= "1111"; --BLUE
    else
      R <= "0000";
      G <= "0000";
      B <= "0000";
    end if;

  elsif (hpos > 420 and hpos < 660 and vpos < 275 and vpos > 55) then
    if from_hcsr_01< 34800 then
      R <= "1111";
      G <= "0000";
      B <= "0000"; --RED
    elsif from_hcsr_01< 69600 and from_hcsr_01> 34800 then
      R <= "1000";
      G <= "0010";
      B <= "0011"; --BROWN
    elsif from_hcsr_01< 104400 and from_hcsr_01> 69600 then
      R <= "1111";
      G <= "1111";
      B <= "0010"; --YELLOW
    elsif from_hcsr_01< 150800 and from_hcsr_01> 104400 then
      R <= "0000";
      G <= "1110";
      B <= "0000"; --GREEN
    elsif from_hcsr_01> 150800 then
      R <= "0000";
      G <= "0111";
      B <= "1111"; --BLUE
    else
      R <= "0000";
      G <= "0000";
      B <= "0000";
    end if;
    
  elsif (hpos < 410 and hpos > 170 and vpos > 285 and vpos < 515) then
    if from_hcsr_10< 34800 then
      R <= "1111";
      G <= "0000";
      B <= "0000"; --RED
    elsif from_hcsr_10< 69600 and from_hcsr_10> 34800 then
      R <= "1000";
      G <= "0010";
      B <= "0011"; --BROWN
    elsif from_hcsr_10< 104400 and from_hcsr_10> 69600 then
      R <= "1111";
      G <= "1111";
      B <= "0010"; --YELLOW
    elsif from_hcsr_10< 150800 and from_hcsr_10> 104400 then
      R <= "0000";
      G <= "1110";
      B <= "0000"; --GREEN
    elsif from_hcsr_10> 150800 then
      R <= "0000";
      G <= "0111";
      B <= "1111"; --BLUE
    else
      R <= "0000";
      G <= "0000";
      B <= "0000";
    end if;

  elsif (hpos > 420 and hpos < 660 and vpos > 285 and vpos < 515) then
    if from_hcsr_11< 34800 then
      R <= "1111";
      G <= "0000";
      B <= "0000"; --RED
    elsif from_hcsr_11< 69600 and from_hcsr_11> 34800 then
      R <= "1000";
      G <= "0010";
      B <= "0011"; --BROWN
    elsif from_hcsr_11< 104400 and from_hcsr_11> 69600 then
      R <= "1111";
      G <= "1111";
      B <= "0010"; --YELLOW
    elsif from_hcsr_11< 150800 and from_hcsr_11> 104400 then
      R <= "0000";
      G <= "1110";
      B <= "0000"; --GREEN
    elsif from_hcsr_11> 150800 then
      R <= "0000";
      G <= "0111";
      B <= "1111"; --BLUE
    else
      R <= "0000";
      G <= "0000";
      B <= "0000";
    end if;
    
    
-----NUMBERSSSSSSSS
----------digit4
  elsif ((hpos > 678 and hpos <682 and vpos > 265 and vpos<295) or
        (hpos > 689 and hpos <693 and vpos > 265 and vpos<295) or
        (hpos > 678 and hpos <693 and vpos > 265 and vpos<269) or
        (hpos > 678 and hpos <693 and vpos > 291 and vpos<295)) and
        (bridge(4) = '0') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
  elsif (hpos>683 and hpos<688 and vpos>265 and vpos<295) and (bridge(4) ='1') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
          
----------digit3
  elsif ((hpos > 698 and hpos <702 and vpos > 265 and vpos<295) or
        (hpos > 709 and hpos <713 and vpos > 265 and vpos<295) or
        (hpos > 698 and hpos <713 and vpos > 265 and vpos<269) or
        (hpos > 698 and hpos <713 and vpos > 291 and vpos<295)) and
        (bridge(3) = '0') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
  elsif (hpos>703 and hpos<708 and vpos>265 and vpos<295) and (bridge(3) ='1') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
----------digit2
  elsif ((hpos > 718 and hpos <722 and vpos > 265 and vpos<295) or
          (hpos > 729 and hpos <733 and vpos > 265 and vpos<295) or
          (hpos > 718 and hpos <733 and vpos > 265 and vpos<269) or
          (hpos > 718 and hpos <733 and vpos > 291 and vpos<295)) and
          (bridge(2) = '0') then
            R <= "1111";
            G <= "1111";
            B <= "1111";
  elsif (hpos>723 and hpos<728 and vpos>265 and vpos<295) and (bridge(2) ='1') then
            R <= "1111";
            G <= "1111";
            B <= "1111";
            
-------------digit1
  elsif ((hpos > 738 and hpos <742 and vpos > 265 and vpos<295) or
          (hpos > 749 and hpos <753 and vpos > 265 and vpos<295) or
          (hpos > 738 and hpos <753 and vpos > 265 and vpos<269) or
          (hpos > 738 and hpos <753 and vpos > 291 and vpos<295)) and
          (bridge(1) = '0') then
            R <= "1111";
            G <= "1111";
            B <= "1111";
  elsif (hpos>743 and hpos<748 and vpos>265 and vpos<295) and (bridge(1) ='1') then
            R <= "1111";
            G <= "1111";
            B <= "1111";
            
---------------digit0
  elsif ((hpos > 758 and hpos <762 and vpos > 265 and vpos<295) or
        (hpos > 769 and hpos <773 and vpos > 265 and vpos<295) or
        (hpos > 758 and hpos <773 and vpos > 265 and vpos<269) or
        (hpos > 758 and hpos <773 and vpos > 291 and vpos<295)) and
        (bridge(0) = '0') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
  elsif (hpos>763 and hpos<768 and vpos>265 and vpos<295) and (bridge(0) ='1') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
          
------------------greater than 1
  elsif ((hpos > 703 and hpos <708 and vpos > 465 and vpos<505) or
        (hpos > 718 and hpos <723 and vpos > 465 and vpos<505) or
        (hpos > 703 and hpos <723 and vpos > 465 and vpos<470) or
        (hpos > 703 and hpos <723 and vpos > 500 and vpos<505)) and
        (compare(1) = '0') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
  elsif (hpos>709 and hpos<717 and vpos>465 and vpos<505) and (compare(1) ='1') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
          
----------------------greater than 2
  elsif ((hpos > 728 and hpos <733 and vpos > 465 and vpos<505) or
        (hpos > 743 and hpos <748 and vpos > 465 and vpos<505) or
        (hpos > 728 and hpos <748 and vpos > 465 and vpos<470) or
        (hpos > 728 and hpos <748 and vpos > 500 and vpos<505)) and
        (compare(0) = '0') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
  elsif (hpos>734 and hpos<742 and vpos>465 and vpos<505) and (compare(0) ='1') then
          R <= "1111";
          G <= "1111";
          B <= "1111";
          
-------------------color blocks
  elsif ((hpos > 753 and hpos <773 and vpos > 385 and vpos<405)) then
    R <= "1111";
    G <= "0000";
    B <= "0000"; ---RED
  elsif ((hpos > 753 and hpos <773 and vpos > 410 and vpos<430)) then
    R <= "1000";
    G <= "0010";
    B <= "0011"; ---BROWN
  elsif ((hpos > 753 and hpos <773 and vpos > 435 and vpos<455)) then
    R <= "1111";
    G <= "1111";
    B <= "0010"; ---YELLOW
  elsif ((hpos > 753 and hpos <773 and vpos > 460 and vpos<480)) then
    R <= "0000";
    G <= "1110";
    B <= "0000"; ---GREEN
  elsif ((hpos > 753 and hpos <773 and vpos > 485 and vpos<505)) then
    R <= "0000";
    G <= "0111";
    B <= "1111"; ---BLUE
  else
    R <= "0000";
    G <= "0000";
    B <= "0000";
  end if;
  
if (hpos < 799) then
  hpos <= hpos + 1;
else
  hpos <= 0;
  if (vpos < 524) then
    vpos <= vpos + 1;
  else
    vpos <= 0;
  end if;
end if;

if (hpos > 16 and hpos < 112) then
  h_out <= '0';
else
  h_out <= '1';
end if;

if (vpos > 9 and vpos < 12) then
  v_out <= '0';
else
  v_out <= '1';
end if;
end if;
end process;
end Behavioral;
