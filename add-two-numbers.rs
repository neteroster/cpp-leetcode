// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>
    ) -> Option<Box<ListNode>> {
        let mut r = 0;
        let mut x_pos = l1.as_ref();
        let mut y_pos = l2.as_ref();
        let mut result = Some(Box::new(ListNode::new(0)));
        let mut pos = result.as_mut();
        loop {
            match (x_pos, y_pos) {
                (None, None) => {
                    if r >= 10 {
                        Solution::add_node(
                            r / 10,
                            pos.unwrap()
                        );
                    }
                    break;
                },
                (Some(x), Some(y)) => {
                    let lsum = x.val + y.val + r / 10;
                    pos = Some(Solution::add_node(
                        lsum % 10,
                        pos.unwrap()
                    ));
                    r = lsum;
                },
                (Some(x), None) => {
                    let lsum = x.val + r / 10;
                    pos = Some(Solution::add_node(
                        lsum % 10,
                        pos.unwrap()
                    ));
                    r = lsum;
                },
                (None, Some(y)) => {
                    let lsum = y.val + r / 10;
                    pos = Some(Solution::add_node(
                        lsum % 10,
                        pos.unwrap()
                    ));
                    r = lsum;
                }

            }
            if x_pos.is_some() { x_pos = x_pos.unwrap().next.as_ref() };
            if y_pos.is_some() { y_pos = y_pos.unwrap().next.as_ref() };
        }

        result.unwrap().next
    }

    pub fn add_node(val: i32, pos: &mut Box<ListNode>) -> &mut Box<ListNode> {
        let new_node: Box<ListNode> = Box::new(ListNode::new(val));
        pos.next = Some(new_node);
        pos.next.as_mut().unwrap()
    }
}
