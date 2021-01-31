
pub fn wpm_to_ms_per_dit(wpm: u8) -> u32 {
   let dits_per_second = (wpm * 50) / 60;
   return = 1000 / dits_per_second;
}