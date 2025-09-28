import random
import subprocess

def vending_reference(seq):
    
    balance = 0
    result = []
    for coin in seq:
        balance += coin
        if balance >= 15:
            result.append(1)   
            balance = 0        
        else:
            result.append(0)   
    return result



coins = [random.choice([5, 10]) for _ in range(20)]
expected_output = vending_reference(coins)

print("Coins:", coins)
print("Expected:", expected_output)


with open("coins_input.txt", "w") as f:
    for c in coins:
        f.write(str(c) + "\n")


subprocess.run(["iverilog", "-o", "vending_tb", "orange.v", "orange_tb.v"])
proc = subprocess.run(["vvp", "vending_tb"], capture_output=True, text=True)


sim_output = [int(x) for x in proc.stdout.strip().split()]
print("Simulated:", sim_output)


if sim_output != expected_output:
    print( "Results do not match")
    for i, (exp, sim) in enumerate(zip(expected_output, sim_output)):
        if exp != sim:
            print(f" Step {i}: expected {exp}, got {sim}")
else:
    print("Simulation matches reference model")
