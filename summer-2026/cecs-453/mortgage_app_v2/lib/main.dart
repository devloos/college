import 'package:flutter/material.dart';
import 'dart:math' as Math;
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:shared_preferences/shared_preferences.dart';

// CECS 453
// Lab assignment 5
// Just Me: Carlos Aguilera
// Video link: https://www.loom.com/share/7531da1ba73c48a9bdd55038cae04c61

enum Years { ten, fifteen, thirty }

class Mortgage {
  final Years years;
  final double amount;
  final double interestRate;

  Mortgage({
    required this.years,
    required this.amount,
    required this.interestRate,
  });

  int get yearsInt {
    switch (years) {
      case Years.ten:
        return 10;
      case Years.fifteen:
        return 15;
      case Years.thirty:
        return 30;
    }
  }

  int get totalMonths {
    return yearsInt * 12;
  }

  String get formattedInterestRate {
    final rate = interestRate * 100;
    return '${rate.toStringAsFixed(2)}%';
  }

  double calculateMonthlyPayment() {
    final r = interestRate / 12;
    final n = totalMonths;

    if (r == 0) return amount / n;

    final monthlyPayment =
        amount * r * Math.pow(1 + r, n) / (Math.pow(1 + r, n) - 1);

    return monthlyPayment;
  }

  double calculateTotalPayment() {
    return calculateMonthlyPayment() * totalMonths;
  }
}

// unimplemented provider for shared preferences
// we will then override this provider with the actual provider in the main function
final sharedPrefsProvider = Provider<SharedPreferences>((ref) {
  throw UnimplementedError();
});

class MortgageNotifier extends Notifier<Mortgage> {
  @override
  Mortgage build() {
    final prefs = ref.watch(sharedPrefsProvider);
    // Load saved values or use defaults
    return Mortgage(
      years: Years
          .values[prefs.getInt('years') ?? 2], // Default to thirty (index 2)
      amount: prefs.getDouble('amount') ?? 100000.0,
      interestRate: prefs.getDouble('interestRate') ?? 0.035,
    );
  }

  void updateMortgage(Mortgage newMortgage) {
    state = newMortgage; // Update UI
    // Save to disk
    final prefs = ref.read(sharedPrefsProvider);
    prefs.setInt('years', newMortgage.years.index);
    prefs.setDouble('amount', newMortgage.amount);
    prefs.setDouble('interestRate', newMortgage.interestRate);
  }
}

final mortgageProvider = NotifierProvider<MortgageNotifier, Mortgage>(
  MortgageNotifier.new,
);

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  final prefs = await SharedPreferences.getInstance();

  runApp(
    ProviderScope(
      overrides: [sharedPrefsProvider.overrideWithValue(prefs)],
      child: const MyApp(),
    ),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Mortgage Calculator',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: const HomeScreen(),
    );
  }
}

class HomeScreen extends ConsumerStatefulWidget {
  const HomeScreen({super.key});

  @override
  ConsumerState<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends ConsumerState<HomeScreen> {
  bool _isSelected = false;

  @override
  Widget build(BuildContext context) {
    final mortgage = ref.watch(mortgageProvider);

    return Scaffold(
      appBar: AppBar(title: const Text('Mortgage Calculator')),
      body: Center(
        child: Container(
          padding: const EdgeInsets.all(20),
          child: Column(
            children: [
              Row(
                children: [
                  const Text('Years:', style: TextStyle(fontSize: 20)),
                  const SizedBox(width: 100),
                  Text(
                    mortgage.yearsInt.toString(),
                    style: const TextStyle(fontSize: 20),
                  ),
                ],
              ),
              Row(
                children: [
                  const Text('Amount:', style: TextStyle(fontSize: 20)),
                  const SizedBox(width: 80),
                  Text(
                    "\$${mortgage.amount.toStringAsFixed(2)}",
                    style: const TextStyle(fontSize: 20),
                  ),
                ],
              ),
              Row(
                children: [
                  const Text('Interest Rate:', style: TextStyle(fontSize: 20)),
                  const SizedBox(width: 35),
                  Text(
                    mortgage.formattedInterestRate,
                    style: const TextStyle(fontSize: 20),
                  ),
                ],
              ),
              const SizedBox(height: 20),
              const Divider(color: Colors.grey),
              const SizedBox(height: 10),
              Row(
                children: [
                  const Text(
                    'Monthly Payment:',
                    style: TextStyle(fontSize: 20),
                  ),
                  const SizedBox(width: 30),
                  Text(
                    "\$${mortgage.calculateMonthlyPayment().toStringAsFixed(2)}",
                    style: const TextStyle(fontSize: 20),
                  ),
                ],
              ),
              const SizedBox(height: 10),
              Row(
                children: [
                  const Text('Total Payment:', style: TextStyle(fontSize: 20)),
                  const SizedBox(width: 57),
                  Text(
                    "\$${mortgage.calculateTotalPayment().toStringAsFixed(2)}",
                    style: const TextStyle(fontSize: 20),
                  ),
                ],
              ),
              const SizedBox(height: 20),
              Row(
                mainAxisAlignment: MainAxisAlignment.end,
                children: [
                  TextButton(
                    onPressed: () {
                      showDialog(
                        context: context,
                        builder: (context) => AlertDialog(
                          title: const Text(
                            'Terms and Conditions',
                            style: TextStyle(fontSize: 20),
                          ),
                          content: const Text(
                            'I agree to the terms and conditions',
                          ),
                          actions: [
                            TextButton(
                              onPressed: () {
                                setState(() {
                                  _isSelected = false;
                                });
                                Navigator.of(context).pop();
                              },
                              child: const Text(
                                'I disagree',
                                style: TextStyle(color: Colors.red),
                              ),
                            ),
                            TextButton(
                              onPressed: () {
                                setState(() {
                                  _isSelected = true;
                                });
                                Navigator.of(context).pop();
                              },
                              child: const Text('I agree'),
                            ),
                          ],
                        ),
                      );
                    },
                    child: const Text(
                      'Terms and Conditions',
                      style: TextStyle(fontSize: 20, color: Colors.black87),
                    ),
                  ),
                  Checkbox(
                    value: _isSelected,
                    onChanged: (value) {
                      setState(() {
                        _isSelected = value ?? false;
                      });
                    },
                  ),
                ],
              ),
              const SizedBox(height: 20),
              ElevatedButton(
                child: const Text('Modify Mortgage'),
                onPressed: () {
                  Navigator.of(context).push(
                    MaterialPageRoute(
                      builder: (context) => const MortgageSelectionScreen(),
                    ),
                  );
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class MortgageSelectionScreen extends ConsumerStatefulWidget {
  const MortgageSelectionScreen({super.key});

  @override
  ConsumerState<MortgageSelectionScreen> createState() =>
      _MortgageSelectionScreenState();
}

class _MortgageSelectionScreenState
    extends ConsumerState<MortgageSelectionScreen> {
  late Years _selectedYears;
  late final TextEditingController _amountController;
  late final TextEditingController _interestRateController;

  @override
  void initState() {
    super.initState();
    // Read initial values from the provider
    final initialMortgage = ref.read(mortgageProvider);
    _selectedYears = initialMortgage.years;
    _amountController = TextEditingController(
      text: initialMortgage.amount.toString(),
    );
    _interestRateController = TextEditingController(
      text: initialMortgage.interestRate.toString(),
    );
  }

  @override
  void dispose() {
    _amountController.dispose();
    _interestRateController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Select Mortgage')),
      body: Column(
        children: [
          const Text('Select Years'),
          RadioGroup<Years>(
            groupValue: _selectedYears,
            onChanged: (Years? value) {
              setState(() {
                _selectedYears = value ?? Years.thirty;
              });
            },
            child: Column(
              children: [
                RadioListTile<Years>(title: Text('10'), value: Years.ten),
                RadioListTile<Years>(title: Text('15'), value: Years.fifteen),
                RadioListTile<Years>(title: Text('30'), value: Years.thirty),
              ],
            ),
          ),
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
            child: TextFormField(
              controller: _amountController,
              keyboardType: const TextInputType.numberWithOptions(
                decimal: true,
              ),
              decoration: const InputDecoration(labelText: 'Amount'),
            ),
          ),
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
            child: TextFormField(
              controller: _interestRateController,
              keyboardType: const TextInputType.numberWithOptions(
                decimal: true,
              ),
              decoration: const InputDecoration(labelText: 'Interest Rate'),
            ),
          ),
          const SizedBox(height: 20),
          ElevatedButton(
            onPressed: () {
              final initialMortgage = ref.read(mortgageProvider);
              final amount =
                  double.tryParse(_amountController.text) ??
                  initialMortgage.amount;
              final interestRate =
                  double.tryParse(_interestRateController.text) ??
                  initialMortgage.interestRate;

              final newMortgage = Mortgage(
                years: _selectedYears,
                amount: amount,
                interestRate: interestRate,
              );

              // update state and save to shared preferences in one go
              ref.read(mortgageProvider.notifier).updateMortgage(newMortgage);

              Navigator.of(context).pop();
            },
            child: const Text('Calculate Mortgage'),
          ),
        ],
      ),
    );
  }
}
