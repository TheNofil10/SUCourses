(define symbol-length
(lambda (inSym)
(if (symbol? inSym)
(string-length (symbol->string inSym))
0
)
)
)


(define sequence?
  (lambda (inSeq)
    (if (null? inSeq)
      #t
      (if (list? inSeq)
        (if (symbol? (car inSeq))
          (if (eq? 1 (symbol-length (car inSeq)))
            (sequence? (cdr inSeq))
            #f
          )
          #f
        )
        #f
      )
    ) 
  )
)


(define same-sequence?
  (lambda (inSeq1 inSeq2)
    (if (and (null? inSeq1) (null? inSeq2))
      #t
      (if (or (null? inSeq1) (null? inSeq2))
        #f
        (if (sequence? inSeq1)
          (if (sequence? inSeq2) 
            (if (eq? (car inSeq1) (car inSeq2))
              (same-sequence? (cdr inSeq1) (cdr inSeq2))
              #f
            )
            (error "Not a proper sequence")
          )
          (error "Not a proper sequence")
        ) 
      )
    )
  )
)


(define reverse-sequence
  (lambda (inSeq)
    (if (sequence? inSeq)
      (if (null? inSeq)
        '()
          (append (reverse-sequence (cdr inSeq))
          (list (car inSeq)))
      )
    (error "Not a proper sequence")
    )
  )
)

(define palindrome?
  (lambda (inSeq)
    (if (sequence? inSeq)
      (if (same-sequence? inSeq (reverse-sequence inSeq))
        #t
        #f
      )
      (error "List has a symbol of length more than 1 / conatins a number")
    )
  )
)



(define member?
  (lambda (inSym inSeq)
    (if (and (symbol? inSym) (sequence? inSeq))
      (if (null? inSeq)
        #f
        (if (eq? inSym (car inSeq))
          #t
          (member? inSym (cdr inSeq))
        )
      )
      (error "Not proper Symbol/Sequence")
    )
  )
)

(define remove-member
  (lambda ( inSym inSeq)
    (if (symbol? inSym)
      (if (sequence? inSeq)
        (if (member? inSym inSeq)
          (if (null? inSeq)
            '()
            (if (eq? inSym (car inSeq))
              (cdr inSeq)
              (cons (car inSeq)
              (remove-member inSym (cdr inSeq)))
            )
          )
        (error "Symbol not in sequence")
        )
        (error "Not a proper sequence")
      )
      (error "Not a symbol")
    )
  )
)

(define anagram?
  (lambda (inSeq1 inSeq2)
    (if (and (sequence? inSeq1) (sequence? inSeq2))
      (if (and (null? inSeq1) (null? inSeq2))
        #t
        (if (member? (car inSeq1) inSeq2)
          (anagram? (remove-member (car inSeq1) inSeq2) (remove-member (car inSeq1) inSeq1))
          #f
        )
      )
      (error "Not a proper sequence")
    )
  )
)


(define anapoli?
  (lambda (inSeq1 inSeq2)
    (if (and (sequence? inSeq1) (sequence? inSeq2))
      (if (palindrome? inSeq2)
        (if (anagram? inSeq1 inSeq2)
          #t
          #f
        )
        #f
      )
      (error "Not a proper sequence")
    )
  )
)



 


 

