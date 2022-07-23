use std::convert::TryInto;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut table: [Vec<&str>; 10] = Default::default();
        Solution::init_table(&mut table);

        let mut result: Vec<String> = Vec::new();

        for c in digits.chars().rev() {
            let n: usize = c.to_digit(10).unwrap().try_into().unwrap();
            if result.is_empty() {
                for k in &table[n] {
                    result.push(k.to_string());
                }
                continue;
            }
            let mut vec_temp: Vec<String> = Vec::new();
            for i in &result {
                for j in &table[n] {
                    vec_temp.push(j.to_string().to_owned() + i);
                }
            }
            result = vec_temp.clone();
        }


        result
    }
    pub fn init_table(table: &mut [Vec<&str>; 10]) {
        table[2] = vec!["a", "b", "c"];
        table[3] = vec!["d", "e", "f"];
        table[4] = vec!["g", "h", "i"];
        table[5] = vec!["j", "k", "l"];
        table[6] = vec!["m", "n", "o"];
        table[7] = vec!["p", "q", "r", "s"];
        table[8] = vec!["t", "u", "v"];
        table[9] = vec!["w", "x", "y", "z"];
    }
}
