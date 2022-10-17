library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bridge is
Port (output: out std_logic_vector(4 downto 0);
      from_hcsr_00, from_hcsr_01, from_hcsr_10, from_hcsr_11 : in integer;
      greaterthan: inout std_logic_vector(1 downto 0));
end bridge;

architecture Behavioral of bridge is
signal prox: integer;
signal cm: integer;

begin
greaterthan <= "00" when (from_hcsr_00<=from_hcsr_01 and from_hcsr_00<=from_hcsr_10 and
                        from_hcsr_00<=from_hcsr_11) else
                      "01" when (from_hcsr_01<from_hcsr_00 and from_hcsr_01<=from_hcsr_10 and
                        from_hcsr_01<=from_hcsr_11) else
                      "10" when (from_hcsr_10<from_hcsr_00 and from_hcsr_10<from_hcsr_01 and
                        from_hcsr_10<=from_hcsr_11) else
                      "11" when (from_hcsr_11<from_hcsr_00 and from_hcsr_11<from_hcsr_01 and
                        from_hcsr_11<from_hcsr_10);

prox <= from_hcsr_00 when greaterthan = "00" else
        from_hcsr_01 when greaterthan = "01" else
        from_hcsr_10 when greaterthan = "10" else
        from_hcsr_11 when greaterthan = "11";
        
output <= "11111" when prox<5000 else
          "11100" when (prox<20000 and prox>5000) else --28
          "11010" when (prox<30000 and prox>20000) else --26
          "11000" when (prox<40000 and prox>30000) else --24
          "10111" when (prox<50000 and prox>40000) else --23
          "10101" when (prox<60000 and prox>50000) else --21
          "10011" when (prox<75000 and prox>60000) else --19
          "10001" when (prox<85000 and prox>75000) else --17
          "10000" when (prox<95000 and prox>85000) else --16
          "01110" when (prox<100000 and prox>95000) else --14
          "01101" when (prox<110000 and prox>100000) else --13
          "01011" when (prox<120000 and prox>110000) else --11
          "01001" when (prox<130000 and prox>120000) else --9
          "01000" when (prox<140000 and prox>130000) else --8
          "00110" when (prox<150000 and prox>140000) else --6
          "00101" when (prox<160000 and prox>150000) else --5
          "00011" when (prox<165000 and prox>160000) else --3
          "00000";
end Behavioral;
