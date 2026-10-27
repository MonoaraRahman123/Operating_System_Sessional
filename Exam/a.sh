read -p "Enter Employee ID: " employee_ID
read -p "Total Sales Amount: " Total_Sales_Amount

if (( Total_Sales_Amount <= 5000 )); then
    commission=0
elif (( Total_Sales_Amount > 5000 && Total_Sales_Amount <= 15000 )); then
    commission=10
else
    commission=15
fi

if(( Commission > 0 )); then
    commission=$((commission*2.5%))
fi

echo "Employee ID = $employee_ID"
echo "Total Sales Amount = $Total_Sales_Amount"
echo "Commision = $commission"